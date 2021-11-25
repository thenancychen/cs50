import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # TODO: Read database file into a variable
    # convert database file into dictionary
    database_file = csv.DictReader(open(sys.argv[1]))

    # TODO: Read DNA sequence file into a variable
    dna_file = open(sys.argv[2]).read()

    # TODO: Find longest match of each STR in DNA sequence
    # create dictionary to take text file and runs longest_match on DNA string
    database_matches = {}
    for subsequence in database_file.fieldnames[1:]:
        database_matches[subsequence] = str(longest_match(dna_file, subsequence))

    # TODO: Check database for matching profiles
    for row in database_file:
        dna_match = True
        for subsequence in database_file.fieldnames[1:]:
            if row[subsequence] != database_matches[subsequence]:
                dna_match = False
        if dna_match:
            print(row['name'])
            return
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
