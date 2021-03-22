*Report of HW3*

* learning experience
  *how to use function to compare the items  
  
* How to use the function
  * Prototype of the function: 
   
     **fun(void* buf , size_t n , size_t size, int (*cmp) (const void*n0 , const void* n1)) **
      
        * void* buf             :  the buffer which needs sorting
        * size_t  n             :  how many items in the buf
        * size_t size           :  how many size for each item in the buffer 
        * int (*cmp) (const void*n0 , const void* n1) : the function that decides the sorting order
        
* limitation
  * the size of each item in the buffer should be equal
  * the items that need sorting should have the same type 
