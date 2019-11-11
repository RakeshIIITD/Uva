
# coding: utf-8

# In[1]:


from copy import deepcopy
import queue 


# In[2]:


mat = [
        [1,0,0,-1],
        [1,0,0,-1],
        [1,0,0,-1],
        [1,0,0,-1]
      ]
# mat = 
#       [
#         [1,0,0,0,-1],
#         [1,0,0,0,-1],
#         [1,0,0,0,-1],
#         [1,0,0,0,-1],
#         [1,0,0,0,-1]
#       ]


# In[3]:


N = len(mat)
M = len(mat[0])


# In[4]:


## FOUR DIRECTIONS

d1 = (-1,-1)   # up left
d2 = (1,1)     # down right
d3 = (1,-1)     # down left
d4 = (-1,1)     # up right


# In[5]:


def print_output(l):
    for i in l:
        for row in i:
            print(row)
        print('='*13)


# In[6]:


def valid(i,j,state):
    if i<0 or j<0 or i>=N or j>=M:
        return False
    else:
        if state[i][j]!=0:
            return False
        else:
            return True


# In[7]:


# generate possibilites for (i,j)

def generate_dir(i,j,state,d):
    
    # unidirectional movement
    
    l = []
    state_copy = deepcopy(state)
    
    while True:

        if valid(i+d[0],j+d[1],state_copy):

            pawn = state_copy[i][j]

            state_copy[i][j] = 0

            i = i+d[0]
            j = j+d[1]

            state_copy[i][j] = pawn 

            l.append(deepcopy(state_copy))

        else:
            break
    return l
  


# In[8]:


# generates state in four directions

def generate(i_orig,j_orig,state):
    
    l1 = generate_dir(i_orig,j_orig,state,d1)
    l2 = generate_dir(i_orig,j_orig,state,d2)
    l3 = generate_dir(i_orig,j_orig,state,d3)
    l4 = generate_dir(i_orig,j_orig,state,d4)
    
    return l1+l2+l3+l4  


# In[9]:


#print_output(generate(0,0,mat))


# In[10]:


def is_goal(d):
    if (d[0][0]+d[1][0]+d[2][0]+d[3][0]==-4) and (d[0][3]+d[1][3]+d[2][3]+d[3][3]==4):
        return True
    else:
        return False


# In[11]:


def neighbors(mat):
    
    states = []
    
    for i in range(0,N):
        for j in range(0,M):
            
            if mat[i][j]!=0:
                
                states+=generate(i,j,mat)
    return states


# In[12]:


# SOLUTION

level = 100
nodes_expanded = 1

def h(node):
    return hash(str(node))


# In[13]:


def solve():
    global level,nodes_expanded
    d = {}
    parent = {}
    q = queue.Queue() 
    q.put(mat)
    
    d[h(mat)] = 0
    
    u = mat
    step = level/20
    
    while d[h(u)]!=level:

        u = q.get()
        nodes_expanded+=1
        if nodes_expanded%10000==0:
            print("Level : "+str(d[h(u)]))
            
        for node in neighbors(u):
            
            if d.get(h(node))==None:
                q.put(node)
                d[h(node)] = 1+d[h(u)]
                parent[h(node)] = u

                if is_goal(node):
                    print("Solution")
                    print(d[h(node)])
                    print("Nodes Expanded : "+str(nodes_expanded))
                    return parent,node,d[h(node)]
    
parent,node, steps = solve() 


# In[14]:


# PRINT SOLUTION

solution = [node]

while parent.get(h(node))!=None:
    k = parent[h(node)]
    solution.append(k)
    node = k
    
print("Steps : "+str(steps))
print_output(list(reversed(solution)))

