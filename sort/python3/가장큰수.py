def check_duplicate(string):
    if len(string) > len(set(string)):
        return True
    else:
        return False
    

def solution(numbers):
    answer = ''
    temp_number = []
    numbers.sort()
    answer_number = []
    for num in numbers:
        if num < 10:
            temp_number.append([((((num * 10) + num) * 10 + num) * 10 + num),num])
        elif num < 100:
            temp_number.append([((num * 100) + num),num])
        elif num < 1000:
            temp_number.append([(num * 10 + (num / 100)),num])
        else:
            temp_number.append([num,num])
        
            
   
    temp_number.sort(reverse= True)
    #print(temp_number)
    for i in temp_number:
        answer_number.append(str(i[1]))
    
   

    #print(answer_number)
    answer = "".join(answer_number)
    
    answer = str(int(answer))
    
    
    return answer