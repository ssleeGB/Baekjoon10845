//
//  main.c
//  baekjoon10845
//
//  Created by 이승섭 on 2018. 12. 5..
//  Copyright © 2018년 이승섭. All rights reserved.
//

#include <stdio.h>

void process_queue()
{
    
    int cnt = 0;
    int i, j, k;
    char op[10];
    
    int queue[100];
    int queue_length = 0;
    FILE *fp = fopen("input.txt","r");
    
    fscanf(fp, "%d", &cnt);
    printf("%d\n", cnt);
    
    
    for(i=0;i<cnt;i++)
    {
        
        //handle input here
        fscanf(fp, "%s", op);
        int result = strcmp("push", op);
        int value = 0;
        printf("%s ", op);
        
        if(strcmp("push", op) == 0)
        { // if op is "push"
            fscanf(fp, "%d", &value);
            printf("%d", value);
        }
        printf("\n");
        
        
        // process stack operation
        if(strcmp("push", op) == 0 )
        {
            queue[queue_length] = value;
            queue_length++;
        }
        
        if(strcmp("pop", op) == 0 )
        {
            if(queue_length > 0)
            {
                printf("%d\n", queue[0]);
                for(k = 0; k <= queue_length; k++)
                {
                    queue[k] = queue[k + 1];
                }
                queue_length--;
            }
            else if(queue_length == 0)
            {
                printf("-1\n");
            }
            
        }
        
        if(strcmp("size", op) == 0 )
        {
            printf("%d\n", queue_length);
        }
        
        if(strcmp("empty", op) == 0 )
                          {
            if(queue_length == 0){
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        
        if(strcmp("front", op) == 0 )
        {
            if(queue_length > 0)
            {
                printf("%d\n", queue[0]);
            }
            else if(queue_length == 0)
            {
                printf("-1\n");
            }
        }
        
        if(strcmp("back", op) == 0 )
        {
            if(queue_length > 0)
            {
                printf("%d\n", queue[queue_length-1]);
            }
            else if(queue_length == 0)
            {
                printf("-1\n");
            }
        }
//        printf("-------- stack result ---------\n");
//        for(j=0;j<stack_length;j++){
//            printf("%d ", stack[j]);
//        }
//        printf("\n");
    }
    
    
    //printf("%s\n", op);
    
    fclose(fp);
    
}


int main(void)
{
    //stack_problem();
    process_queue();
    return 0;
}
