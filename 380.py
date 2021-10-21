class RandomizedSet:

    def __init__(self):
        self.elements = {}
        self.n = 0

    def insert(self, val: int) -> bool:
        if val not in self.elements:
            self.elements[val] = True
            self.n += 1
            return True
        return False

    def remove(self, val: int) -> bool:
        if val in self.elements:
            self.elements.pop(val)
            self.n -= 1
            return True
        return False

    def getRandom(self) -> int:
        rand = random.randint(0, self.n-1)
        return list(self.elements.keys())[rand]

