# 关于随机数
![[Pasted image 20250605012958.png]]
![[Pasted image 20250605013016.png]]

# 关于find()
![[Pasted image 20250605013310.png]]

# 如何给vector赋值
Vector vec10 = {1, 2, 3, 4, 5, 6};是错误的

​**方法1：逐个赋值**

Vector vec10(6); 
vec10[0] = 1; vec10[1] = 2; // … 手动赋值

**列表初始化（C++11 及以后）**

std::vector vec = {1, 2, 3, 4, 5}; // 直接初始化
std::vector vec_str{"a", "b", "c"};


# 关于零向量，你会表达吗
![[Pasted image 20250605014306.png]]

### cin.clear() 和 cin.ignore()的区别

![[Pasted image 20250607164508.png]]

# 怎么输出固定位数小数
```cpp
       os << "(" << setw(3) << p.x << "," << setw(3) << p.y << ")";
```