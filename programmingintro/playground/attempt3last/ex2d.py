class Worker:
    def __init__(self, worker_num, fname, lname, work_experience_company, salary, age):
        self.worker_num = worker_num
        self.fname = fname
        self.lname = lname
        self.work_experience_company = work_experience_company
        self.salary = salary
        self.age = age

    def worker_information(self):
        print(f"{self.worker_num} | {self.fname} | {self.lname} | {self.age} old | {self.work_experience_company} yrs exp | ${self.salary}")

    def salary_bonus(self):
        if 5 <= self.work_experience_company <= 10:
            return self.salary + (self.salary * (1.5 / 100))
        elif self.work_experience_company > 10:
            return self.salary + (self.salary * (2.0 / 100))
        elif self.work_experience_company < 5:
            return self.salary + (self.salary * (0.5 / 100))
        
workers_list = []

while True:
    try:
        n = int(input("Amount of workers: "))
        if n > 0:
            for i in range(n):
                while True:
                    try:
                        worker_num = int(input(f"{i+1} Worker Num: "))
                        fname = input(f"{i+1} Worker Fname: ")
                        lname = input(f"{i+1} Worker Lname: ")
                        work_experience_company = int(input(f"{i+1} Worker Exp: "))
                        salary = float(input(f"{i+1} Worker Salary: "))
                        age = int(input(f"{i+1} Worker Age: "))
                        workers_list.append(Worker(worker_num, fname, lname, work_experience_company, salary, age))
                        break
                    except ValueError:
                        print("Invalid input.")
            break
        else:
            print("Invalid number.")
    except ValueError:
        print("Invalid input.")

def search_by_num(workers_list, worker_num):
    result = False
    for x in workers_list:
        if x.worker_num == worker_num:
            result = True
    return result
        
def search_by_name_experience(workers_list, fname, work_experience_company):
    ls = (list(filter(lambda x: x.fname == fname and x.work_experience_company == work_experience_company, workers_list)))
    if len(ls) == 0:
        print("No such workers.")
    else:
        return ls
    
def add_worker(workers_list, worker):
    workers_list.append(worker)

def remove_worker(worker_num):
    found = False
    for x in workers_list:
        if x.worker_num == worker_num:
            print("Information deleted !!!")
            workers_list.remove(x)
            found = True
            break
    if not found:
        print("Wrong worker num !!!")
