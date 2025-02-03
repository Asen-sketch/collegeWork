class Worker:
    def __init__(self, worker_num, fname, lname, work_experience_company, salary, age):
        self.worker_num = worker_num
        self.fname = fname
        self.lname = lname
        self.work_experience_company = work_experience_company
        self.salary = salary
        self.age = age

    def worker_information(self):
        print(f"{self.worker_num} | {self.fname} {self.lname} | {self.age} | {self.work_experience_company} | {self.salary}")

    def salary_bonus(self):
        if self.work_experience_company >= 5 and self.work_experience_company <= 10:
            return self.salary + (self.salary * (1.5/100))
        elif self.work_experience_company < 5:
            return self.salary + (self.salary * (0.5/100))
        else:
            return self.salary + (self.salary * (2/100))
        
workers_list = []
while True:
    try:
        num = int(input("Number of workers:"))
        while len(workers_list) < num:
            try:
                worker_num = int(input("Worker num:"))
                fname = input("First name: ")
                lname = input("Last name: ")
                work_experience_company = int(input("Work experience: "))
                salary = int(input("Salary: "))
                age = int(input("Age: "))
                workers_list.append(Worker(worker_num, fname, lname, work_experience_company, salary, age))
            except ValueError:
                print("Invalid data.")
        break
    except ValueError:
        print("Invalid input.")

def search_by_num(workers_list, worker_num):
    result = False
    for x in workers_list:
        if x.worker_num == worker_num:
            result = True
    return result

def search_by_name_experience(workers_list, fname, work_experience_company):
    ls = list(filter(lambda x: x.fname == fname and x.work_experience_company == work_experience_company, workers_list))
    if len(ls) == 0:
        print("No such workers.")
    else:
        return ls
    
def add_worker(workers_list, worker):
    workers_list.append(worker)

def remove_worker(worker_num):
    for x in workers_list:
        if x.worker_num == worker_num:
            workers_list.remove(x)