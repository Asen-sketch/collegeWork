class Soldier:
    def __init__(self, name, rank, servicenumber):
        self._rank = rank
        self._servicenumber = servicenumber
        self.name = name

    @property
    def rank(self):
        return self._rank

    @property
    def servicenumber(self):
        return self._servicenumber

    def receive_rank(self, new_rank):
        print(f"{self.name} received the military rank of {new_rank}.")
        self._rank = new_rank

    def confirm_serial_number(self, entered_number):
        return entered_number == self._servicenumber

    def promote(self):
        print(f"{self.name} has been promoted.")

    def demote(self):
        print(f"{self.name} has been demoted.")

    @staticmethod
    def display_info_decorator(func):
        def wrapper(self, *args, **kwargs):
            print(f"Soldier Information: {self.name}")
            print(f"Rank: {self._rank}")
            print(f"Service Number: {self._servicenumber}")
            return func(self, *args, **kwargs)

        return wrapper

    @display_info_decorator
    def receive_rank_decorated(self, new_rank):
        self.receive_rank(new_rank)

soldier_example = Soldier("John Doe", "Private", "12345")

soldier_example.receive_rank_decorated("Sergeant")
