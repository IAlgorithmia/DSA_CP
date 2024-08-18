def counter(sentence):
    new_sentence = sentence.split()
    not_needed = ["'", ".", ",", "?", "\"", "!", ":", ")", "(", ";"]
    my_dict = {}
    new_list = []
    for item in new_sentence:
        for i in item:
            if (i in not_needed):
                item = item.replace(i, "")
        if (len(item) != 0):
            new_list.append(item)
    for i in new_list:
        if (i in my_dict):
            my_dict[i] += 1
        else:
            my_dict[i] = 1
    return my_dict
answer = counter("Hey! It's me, your friend Jesus :)")
print(answer)