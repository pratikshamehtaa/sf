import os
import sys

def count_vowels(sentence):
    vowels = set("aeiouAEIOU")
    count = sum(1 for char in sentence if char in vowels)
    print(f"Parent Process - Number of Vowels: {count}")

def count_words(sentence):
    words = sentence.split()
    count = len(words)
    print(f"Child Process - Number of Words: {count}")

def main():
    sentence = "Hello, world! This is a sample sentence."


    pid = os.fork()

    if pid > 0:

        count_vowels(sentence)
        os.wait()  
    elif pid == 0:
       
        count_words(sentence)
        sys.exit(0)  

if __name__ == "__main__":
    main()
