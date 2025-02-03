class Animal:
    def __init__(self, name, animal_type, legs):
        self.name = name
        self.animal_type = animal_type
        self.legs = legs

    def voice(self):
        print(f"{self.name} sings.")

    def move(self):
        print(f"{self.name} moves.")

class Dog(Animal):
    def __init__(self, name, breed):
        super().__init__(name, animal_type="Dog", legs=4)
        self.breed = breed

    def bark(self):
        print(f"{self.name} barks.")

class Bird(Animal):
    def __init__(self, name, wingspan):
        super().__init__(name, animal_type="Bird", legs=2)
        self.wingspan = wingspan

    def fly(self):
        print(f"{self.name} is flying with a wingspan of {self.wingspan} meters.")

animal_example = Animal("Jenny", "Mammal", 4)
dog_example = Dog("Buddy", "Golden Retriever")
bird_example = Bird("Tweetie", 1.2)

print("Animal Example:")
animal_example.voice()
animal_example.move()
print("\nDog Example:")
dog_example.voice()
dog_example.move()
dog_example.bark()
print("\nBird Example:")
bird_example.voice()
bird_example.move()
bird_example.fly()
