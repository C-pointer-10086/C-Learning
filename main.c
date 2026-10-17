#include <stdio.h>
#include <stdbool.h>
void show_menu(){
    printf("\n========== 菜单 ==========\n");
    printf("1. 显示所有成绩\n");
	printf("2. 计算平均分\n");
	printf("3. 查找最高分和最低分\n");
	printf("4. 统计各分数段人数\n");
	printf("5. 退出\n");
	printf("请选择（1-5）：");
}
void show_scores(int marks[],int numbers){
    for(int i=1;i<=numbers;i++){
    printf("学生%d的成绩是%d\n",i,marks[i-1]);
    }
}
float calulate_average(int marks[],int numbers){
    int sum=0;
    float average;
    for(int i=1;i<=numbers;i++){
        sum=sum+marks[i-1];
        }
    average=(float)sum/numbers;
    return average;
}
int find_max(int marks[],int numbers){
    int max=marks[0];
    for(int i=1;i<=numbers;i++){
    if(marks[i-1]>max){
    max=marks[i-1];
     }
     } 
     return max;                 
}
int find_min(int marks[],int numbers){
    int min=marks[0];
    for(int i=1;i<=numbers;i++){
        if(marks[i-1]<min){
        min=marks[i-1];
         }
         }
         return min;
}
void count_grades(int marks[],int numbers){
    int graed_a=0;int graed_b=0;int graed_c=0;int graed_d=0;int graed_e=0;
                            
    for(int i=0;i<numbers;i++){
    	if(marks[i]<=59){graed_e++;}
    	else if(marks[i]<=69){graed_d++;}
    	else if(marks[i]<=79){graed_c++;}
    	else if(marks[i]<=89){graed_b++;}
    	else {graed_a++;}
     }
    printf("\n优秀(90~100)：%d 人\n", graed_a);
    printf("良好(80~89)：%d 人\n", graed_b);
    printf("中等(70~79)：%d 人\n", graed_c);
    printf("及格(60~69)：%d 人\n", graed_d);
    printf("不及格(0~59)：%d 人\n", graed_e);
}
int input_student_numbers(){
    int numbers=1;
    float numbers_interim;
    do{
        if(numbers<=0){
            	printf("学生人数必须是正整数\n");
       	 }else if(numbers>50){
           	 printf("学生人数不得超过50\n");
       	 }
        printf("请输入学生人数(最多50,若是小数自动向下取整): ");
        scanf("%f",&numbers_interim);
        numbers=(int)numbers_interim;
      }while( numbers<=0 || numbers >50);
      return numbers;
}
void input_scores(int marks[],int numbers ){
    float marks_interim=1;
    printf("\n请输入学生成绩(也会自动取整)");
	    for(int i=1;i<=numbers;i++)
	    {	
        do{
        	if(marks_interim<0){
            	printf("不得是负数\n");
        	}else if(marks_interim>100){
            	printf("也不得超过100");
            }
	    	printf("\n学生%d的成绩: ",i);
	    	scanf("%f",&marks_interim);
        	marks[i-1]=(int)marks_interim;
        }while(marks_interim<0 || marks_interim>100);
        }
       
}

int main()
{
		int student_marks[50];//负责存储学生成绩
        
 	 
        int student_numbers=input_student_numbers();
        
	    input_scores(student_marks,student_numbers);
        bool running=true;
        	while(running){
                show_menu();
                int choice;
                float choice_interim;
                
                scanf("%f",&choice_interim);
                choice=(int)choice_interim;
                switch(choice){
                    case 1:
                    		show_scores(student_marks,student_numbers);
                            break;
                    case 2:
                       
                        printf("平均成绩是%.2f\n",calulate_average(student_marks,student_numbers));
                        break;
                        
                      
                    case 3:
                        printf("\n最大值是%d，最小值是%d\n",find_max(student_marks,student_numbers),find_min(student_marks,student_numbers));
                        break;
                        
                        case 4:
                        	count_grades(student_marks,student_numbers);
    						break;
                            
                        
                      case 5:
                      	running=false;
                        printf("goodbye\n");
                        break;
                      default:
                      	printf("无效请求，重新输入");
                          break;
               }     	
            }
	return 0;
}