class HashTable(object):
    def __init__(self):
        self.table = [None]*10000

    def store(self, string):
        """Input is a string that is stored in 
        the table."""
        if self.lookup(string) is -1:
            hash = self.calculate_hash_value(string)
            if hash is not -1:
                if self.table[hash] is not None:
                    self.table[hash].append(string)
                else:
                    self.table[hash] = [string]

    def lookup(self, string):
        """Return the hash value if the
        string is already in the table.
        Return -1 otherwise."""
        hash = self.calculate_hash_value(string)
        if hash is not -1:
            if self.table[hash] is not None:
                if string in self.table[hash]:
                    return hash
        return -1

    def calculate_hash_value(self, string):
        """Helper function to calulate a
        hash value from a string."""
        return ord(string[0])*100 + ord(string[1])
    
# Setup
hash_table = HashTable()

# Test calculate_hash_value
# Should be 8568
print hash_table.calculate_hash_value("UDACITY")

# Test lookup edge case
# Should be -1
print hash_table.lookup("UDACITY")

# Test store
hash_table.store("UDACITY")
# Should be 8568
print hash_table.lookup("UDACITY")

# Test store edge case
hash_table.store("UDACIOUS")
# Should be 8568
print hash_table.lookup("UDACIOUS")