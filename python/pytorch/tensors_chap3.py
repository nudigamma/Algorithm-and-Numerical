import torch 

a = torch.ones(3) # creates a 3x1 tensor filed with one
#print(a)
a[1] # a single element tensor 
a[2]=2.0
#print(a)
# small demonstration on how to save the vertices of a triangle using their coordinates
b = torch.tensor([[4., 1.],[5.,3.],[2.,6.]])
#print(b)
# at any time we can get the tensor shape
#print(b.shape)
# we can initialize tensors with zeros values and tuples

c = torch.rand(3,2,4)


#to access first row second column
#print(b[0,1])
#print(c[0])

all_rows_after_first = b[1:] # implicitly all columns
#print(all_rows_after_first)
all_rows_after_first = b[1:,:] # explicity all columns
#print(all_rows_after_first)
all_row_after_first_only_first_column= b[1:,0]
#print(all_row_after_first_only_first_column)
d = b[None]
#print(d.shape) # adds a dimension

#broadcasting 
img_t = torch.randn(3,5,4) # channels, row, columns
weights = torch.tensor([0.2126,0.715,0.0722]) 

batch_t = torch.randn(2,3,5,5)

# mean  
im_t = torch.tensor([[ [1.,2.],[3.,4.],[5.,6.] ],[[7.,8.],[9.,10.],[11.,12.]]])
print(im_t)
mean_y = im_t.mean(-1) #accross columns
print(mean_y)
mean_x = im_t.mean(-2) #across rows
print(mean_x) 
mean_z = im_t.mean(-3) #across planes
print(mean_z)


print(weights.shape)

img_t = torch.ones(3,5,5,dtype=torch.short).to(torch.double) #doing weighted averaging
weights = torch.tensor([0.4,0.3,0.1],dtype=torch.float32)

unsqueezed_weights = weights.unsqueeze(-1).unsqueeze_(-1)

weighted_img = img_t * unsqueezed_weights
print(img_t.dtype)

