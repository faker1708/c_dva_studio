

# 建立 一个501长的数组，哈希表，然后顺序输出 就ok

ll= list()
while(1):
    try:
        a = input()
        ll.append(a)
    except:
        break

# print(ll)

#### 以上是输入模板，要背诵

n = ll[0]   # 数字 的个数

ht =list()#建立 一个哈希表
for i in range(501):
    ht.append(0)

for i,ele in enumerate(ll):
    if i==0:
        continue
    b = int(ele)
    c = ht[b]
    ht[b]=1

lb = list()
for i,ele in enumerate(ht):
    if(ele==1):
        lb.append(i)

# print('lb',lb)
# a = ll[0]
# b= int(a)
# print(b)

for i,ele in enumerate(lb):
    print(ele)


