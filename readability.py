import cs50


def main():

    user_text = cs50.get_string("Text: ")
    num_letters = counter_letters(user_text)
    num_words = count_words(user_text)
    num_sentences = count_sentences(user_text)

    # calculates l and s average
    l = float(num_letters/num_words * 100)
    s = float(num_sentences/num_words * 100)

    # calculates coleman liau index
    index = round(0.0588 * l - 0.296 * s - 15.8)

    # printing grade from index
    if index > 16:
        print("Grade 16+\n")
    elif index < 1:
        print("Before Grade 1\n")
    else:
        print("Grade", index, "\n")


# letter counter function
def counter_letters(text):

    num_letters = 0
    for letters in range(0, len(text)):
        if text[letters].isalpha():
            num_letters += 1
    return num_letters


# word counter function
def count_words(text):

    num_words = 1
    for words in range(0, len(text)):
        if text[words] == " ":
            num_words += 1
    return num_words


# sentence counter function
def count_sentences(text):

    num_sentences = 0
    for punctuation in range(0, len(text)):
        if text[punctuation] == '!' or text[punctuation] == '?' or text[punctuation] == '.':
            num_sentences += 1
    return num_sentences


main()

