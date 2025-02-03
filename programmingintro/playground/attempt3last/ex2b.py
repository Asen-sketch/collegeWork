class Worker:
    def __init__(self, worker_num, fname, lname, work_experience_company, salary, age):
        self.worker_num = worker_num
        self.fname = fname
        self.lname = lname
        self.work_experience_company = work_experience_company
        self.salary = salary
        self.age = age

    def worker_information(self):
        print(f"{self.worker_num} | {self.fname} | {self.lname} | {self.age} old | {self.work_experience_company} yrs | ${self.salary}")

    def salary_bonus(self):
        if 5 <= self.work_experience_company <= 10:
            return self.salary + (self.salary * (1.5/100))
        elif self.work_experience_company < 5:
            return self.salary + (self.salary * (0.5/100))
        elif self.work_experience_company > 10:
            return self.salary + (self.salary * (2.0/100))
        
workers_list = []
while True:
    try:
        n = int(input("Enter amount of workers: "))
        if n > 0:
            for i in range(n):
                while True:
                    try:
                        print(f"Worker {i+1}")
                        worker_num = int(input("Enter Number of worker: " ))
                        fname = input("Enter first name: ")
                        lname = input("Enter last name: ")
                        work_experience_company = int(input("Enter years experience: "))
                        salary = int(input("Enter salary: "))
                        age = int(input("Enter age: "))
                        workers_list.append(Worker(worker_num, fname, lname, work_experience_company, salary, age))
                        break
                    except ValueError:
                        print("Invalid input.")
        break
    except ValueError:
        print("Invalid input.")

def search_by_num(workers_list, worker_num):
    exists = False
    for x in workers_list:
        if x.worker_num == worker_num:
            exists = True
    return exists

def search_by_name_experience(workers_list, fname, work_experience_company):
    ls = list(filter(lambda x: x.fname == fname and x.work_experience_company == work_experience_company, workers_list))
    if ls:
        return ls
    else:
        print("No such workers.")

def add_worker(workers_list, worker):
    workers_list.append(worker)

def remove_worker(worker_num):
    for x in workers_list:
        if x.worker_num == worker_num:
            workers_list.remove(x)
            print("Information deleted !!!")
        else:
            print("Wrong worker_num !!!")