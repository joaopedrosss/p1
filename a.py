#hoje chove e o carro é azul
#hoje chove e o carro é azul ou a baleia é rosa
#hoje chover e o dia ter 10 graus Celsius equivale ao liverpool ter 2 mundiais
#o flamengo ganha ou o vasco perde e o presidente rouba implica que o liverpool vai vecer ou o manchester city ganha a premier legue
def pure_sentence(word):
    if word.find('nao') != -1:
        return word.replace('nao','')
    else:
        return word

conectivos = ['implica','e','ou','equivale','nao']
conectivosLogicos = ['->','∧','∨', '<->','~']
simbolos = ['M','N','O','P','Q','R','S','U','V','Z','-']

#print("Digite a senteça natural abaixo\nOperadores lógicos: se..entao ; e ; ou ; ..se e somente se..\n")
frase_raw = input(">").strip().split()

#print(frase_raw)

err = 0
sentenca_logica = []
frases = []

count = 0
count_simbolos = 0
inicio = 0 
while count < len(frase_raw):
    element = frase_raw[count]
    if(count_simbolos > 9):
        print("Sentenças em excesso: limite de até 10 senteças ou menos")
        err = 1

    if(element in conectivos):
    
        if element == 'nao':
            sentenca_logica.append(conectivosLogicos[conectivos.index(element)])
            #sentenca_logica.append(simbolos[count_simbolos])
        else:
            sentenca_logica.append(simbolos[count_simbolos])
            sentenca_logica.append(conectivosLogicos[conectivos.index(element)])
            
            f = frase_raw[inicio:count]
            f = " ".join(f)
            frases.append(f)
            count_simbolos +=1
            inicio = count + 1
            
       
    if(count == len(frase_raw)-1):
        sentenca_logica.append(simbolos[count_simbolos])
        f = frase_raw[inicio:count+1]
        frases.append(" ".join(f))

    count+=1

#print(sentenca_logica)
#print(frases)

if (err==0):
    count = 0
    while count<len(frases):
        print("{}: {}".format(simbolos[count],pure_sentence(frases[count])))
        count+=1

    sentenca_completa = " ".join(sentenca_logica)
    print(sentenca_completa)