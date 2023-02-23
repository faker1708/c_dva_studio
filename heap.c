
    #ifndef class_heap
    #define class_heap

    //#include"./string.c"


typedef int inf();

typedef int* inp;
typedef inp inpf();

//typedef inf* inf*;

struct heap{

    // 属性区 继承区
    int** stack;
    int tail;
    int max_length;
    int* dock;  // 用户可以自己放点东西，比如给自己回调传参。

    //  回调函数 
    inf* compare; 

    // api 两个方法
    inf* push;
    inpf* pop;

    /* 
        私有方法可以用int* 来写，而不用inf* 这样外面 拿到还要再转一下，
        可能 就意识到这是私有方法了。
    */

    /*
        主营业务
        
        推入
        弹出
        
        判断    
    
    */
    //inf* is_sort;
    // inf* print;
};

    // 私有函数

    // 可能会接受回调 算了，不接受回调了。不需要
    int class_heap_exchange(struct heap* heap,int x,int y){
        int ** a = heap->stack;
        int* xx = a[x];
        int* yy = a[y];
        a[x]=yy;
        a[y]=xx;
        return 0;
    }


    //　这个 函数 不对。
    int class_heap_max_one(struct heap* heap,int x,int y){
        // 返回大的数的下标。// 由compare决定，也许是小的。

        int** a = heap->stack;


        int out= 0;
        int compare_result = heap->compare(a[x],a[y]);
        if(compare_result==0 || compare_result == 1){
            out  = x;
        }else{
            out = y;
        }

        return out;

    }

    int class_heap_node_sort(struct heap* heap,int i){
        //printf("class_heap_node_sort\n");
        
        int** a = heap->stack;
        int tail = heap->tail;
        int n = tail+1;

        //printf("tail %d\n",tail);
        
        // 给定一个堆 a n 给定一个下标，将其与其子结点变成堆有序

        // 返回与它互换的子节点下标，如果没有就为-1
        
        //printf("%d\n",i);
        if(i<=tail && i>=0){
            // i就是根节点下标。

            int left_index = 2*i+1;
            int right_index = 2*i+2;


            int left_value = 0;
            int right_value = 0;

            //printf("debug\n");
            //printf("left_index %d\n",left_index);
            //printf("right_index %d\n",right_index);
            if(left_index<=n-1){
                //printf("class_heap_node_sort . i==%d l %d r %d\n",i,left_index,right_index);
                //printf("left_value %p",a[left_index]);
                left_value = a[left_index];
                if(right_index<=n-1){
                    // 左右子都存在
                    // 分成四种情况 根比左大，比右大，
                    // 比左小，比右大，
                    // 比左大，比右小，
                    // 比左小，比右小
                    
                    // 
                    //printf("左右子都存在，则选择更大的子，再将根与它比较。\n");
                    int big_son = class_heap_max_one(heap,left_index,right_index);
                    // //printf("big son %d\n",big_son);
                    int biggest = class_heap_max_one(heap,big_son,i);
                    if(i==biggest){
                        return -1;
                    }else{
                        class_heap_exchange(heap,i,big_son);
                        return big_son;
                    }
                }else{
                    //printf("无右子 只有左子\n");
                    
                    int big_son = left_index;
                    int biggest = class_heap_max_one(heap,big_son,i);
                    if(i==biggest){
                        return -1;
                    }else{
                        class_heap_exchange(heap,i,big_son);
                        return big_son;
                    }


                    // if(a[i]>=a[left_index]){
                    //     // 根比左子大，不行动
                    //     return -1;
                    // }else{
                    //     class_heap_exchange(heap,i,left_index);
                    //     return left_index;
                    // }
                }
            }else{

                // 没有左子 没有右子
                //printf("没有左子 没有右子\n");
                return -1;
            }



        }else{
            //printf("class_heap_node_sort error 给定的i不合法.i = %d ,tail = %d\n",i,tail);
            exit(-1);
        }


        return 0;

    }



    int class_heap_down_shift(struct heap* heap,int i){
        // //printf("class_heap_down_shift\n");

        int** a = heap->stack;
        int n = heap->tail+1;

        // 下滤，时间成本 log n
        int now = i;
        // //printf("now %d ",now);
        while(1){
            int c = class_heap_node_sort(heap,now);
            // //printf("返回 %d\n",c);
            if(c==-1){
                // //printf("跳出\n");
                break;
            }else{
                now = c;
            }
        }
        return 0;
    }

    // 本文中，n表示数组长度，而不是尾元素的下标。tail = n-1
    int class_heap_up_shift(struct heap* heap,int i){
        // //printf("class_heap_up_shift\n");

        // 时度，log n
        if(i==0)return -1;
        
        int now = i;
        // //printf("now %d\n",now);
        int patience = 10;

        while(1){
            // if(patience==0)break;patience--;
            // //printf("pp%d",patience);

            // //printf("now %d\n",now);
            // //printf("now %d\n",i);

            now = (now-1)/2;    // 以父之名

            // //printf("now %d\n",now);
            int c = class_heap_node_sort(heap,now);
            // //printf("c %d\n",c);

            if(now==0)return -1;
            if(c>=0){
                // go on
            }else{
                // //printf("没了\n");
                return -1;
            }
        }

        return 0;

    }




    // 私有函数 end

    // 接口方法


    int class_heap_push(struct heap* heap,int* new){
    // int class_heap_push(int**a ,int n,int* new){
        // a 是指针数组 new 是新来的指针。

        int** a = heap->stack;
        int n = heap->tail+1;
        
        int tail = n-1;
        a[n] = new;

        heap->tail++;   // 修改尾巴


        class_heap_up_shift(heap,heap->tail);



        return 0;
    }


    int* class_heap_pop(struct heap* heap){
        // 弹出堆顶的元素，把堆尾放在堆顶，然后重新排序，注意堆长度要减1

        //printf("pop start \n");

        int* head_value;
        int tail_index = heap->tail;
        
        if(tail_index==-1)return 0;
        
        int** stack =  heap->stack;
        
        int head_index = 0;
        
        int* tail_p = stack[tail_index];
        int* head_p = stack[head_index];
        //int now_length = tail_index+1;



        head_value = stack[0];


        stack[0] = tail_p;
        heap->tail--;
        int tail_new = heap->tail;
        //printf("tail_new %d\n",tail_new);
        if(tail_new<=-1){

        }else{

            class_heap_down_shift(heap,0);
        }


        // //printf("pop remain %d ",heap->tail+1);
        //printf("pop end ");
        // //printf("%p ",head_value);
        return head_value;
    }

    int class_heap_is_sort(struct heap * heap){
        // 验证一个数组，是否符合堆序
        // 返回1 表示 大根堆，返回0表示 不满足堆序，返回-1表示 小根堆。

        // way = 1,表示检查 大根序 way = 0 表示检查小根序

        /*
            节点的父子关系
            0节点没有父节点
            i节点的父节点是 (i-1)/2

        
        
        
        */

        // //printf("class_heap_is_sort\n");

        int tail = heap->tail;

        inf* cmp ;
        cmp =(inf*) heap->compare;
        int** stack = heap->stack;

        int out = 0;
        for(int i = 0;i<=tail;i++){
            
            int left = 2*i+1;
            int right = 2*i+2;
            if(left>=tail+1){
                // 查不了
            }else{

                int cr = cmp(stack[i],stack[left]);
                if(cr==1 || cr==0){

                    // 左边满足，再看右边
                    if(right>=tail+1){
                        // 查不了
                    }else{
                        cr = cmp(stack[i],stack[right]);

                        if(cr ==1 || cr==0){
                        // if(a[i]>=a[right]){
                            // ok
                        }else{
                            out = 0;
                            break;
                        }
                    }


                }else{
                    out = 0;
                    break;
                }



            }
            if(i == tail){
                out = 1;
            }

        }

        return out;
    }

    //强制重新排序
    int class_heap_sort(struct heap* heap){
        
        //printf("class_heap_sort\n");
        int** a = heap->stack;
        int tail = heap->tail;
        
        // 时度 n
        for(int i = tail;i>=0;i--){
            // 倒序
            //printf("%d\n",i);
            class_heap_down_shift(heap,i);
            
        }
        // //printf("sort over\n");


        return 0;
    }


    // 接口函数
    struct heap* class_heap_construct(){
        struct heap* heap = malloc(sizeof(struct heap)*1);


        // api
        //heap->stack_to_heap = class_heap_stack_to_heap;
        heap->stack = 0;
        heap->push = class_heap_push;
        heap->pop = class_heap_pop;
        
        return heap;
    }


    // 输出 1 个函数 构造  2 个方法 栈转堆 插入 弹出 


    #endif  /*   class_heap   */
