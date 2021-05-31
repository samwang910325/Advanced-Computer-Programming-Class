import csv 

##read the data
with open('sudoku.csv',encoding="utf-8-sig") as inputcsv: 
    rows=csv.reader(inputcsv)
    D=list(rows)

##process data
rset=[]
cset=[]
gset=[] 

n=len(D)

status=[] 

for i in range(n):
    rset.append([])
    cset.append([])
    status.append([])

for a in range((n//3)):
    gset.append([]  )
    for b in range( (n//3) ):
        gset[a].append([])



for i in range (n):
    for j in range (n) :
        if(D[i][j]=='_') :
            D[i][j]=-1
            rset[i].append(100+j)
            cset[j].append(1000+i)
            status[i].append(0)
            gset[i//3][j//3].append(10+1000*i+j)
        else       :
            D[i][j]=int(D[i][j])
            rset[i].append(D[i][j])
            cset[j].append(D[i][j])
            status[i].append(1)
            gset[i//3][j//3].append(D[i][j])


def findanswer(i,j):
    
    if(i==n):
        for ls in D: print(ls)
        return 
    
    if(status[i][j] ==0) :
        for p in range(1,10):
            
            D[i][j]=p
            rset[i][j]=p
            cset[j][i]=p
            index=(i%3)*3+(j%3)
            gset[i//3][j//3][index]=p
        
            t=set(rset[i]) 
            if(len(t) !=9): continue
            t=set(cset[j]) 
            if(len(t) !=9): continue
            t=set(gset[i//3][j//3]) 
            if(len(t) !=9): continue
            if(j<n-1): findanswer(i,j+1)
            else     : findanswer(i+1,0)
        index=(i%3)*3+(j%3)
        rset[i][j]=100+j
        cset[j][i]=1000+i
        gset[i//3][j//3][index]=10+i*1000+j
    else :
        if(j<n-1): findanswer(i,j+1)
        else     : findanswer(i+1,0)
   


findanswer(0,0)
