#include<stdio.h>
#include<string.h>
struct file{
    char filename[40];
    int status;
};
struct user{
    char username[40];
    struct file files[20];
    int fc;
    int status;
};
int main(){
    int ch,x=1;
    printf("Select:\n1.SingleLevel\n2.TwoLevel\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:{
            int i=0,j;
            char temp[40];
            struct file files[40];
            while(x){
               printf("\nMenu:\n1.CreateFile\n2.RenameFile\n3.DisplayFiles\n4.SearchFile\n5.DeleteFile\n0.Exit\n");
                scanf("%d",&x);
                switch(x){
                    case 1:
                        printf("FileName: ");
                        scanf("%s",temp);
                        strcpy(files[i].filename,temp);
                        files[i++].status=1;
                        break;
                    case 2:
                        printf("FileName: ");
                        scanf("%s",temp);
                        for(j=0;j<i;j++){
                            if(strcmp(files[j].filename,temp)==0){
                                printf("\nChangeTo: ");
                                scanf("%s",temp);
                                strcpy(files[j].filename,temp);
                                break;
                            }
                        }
                        break;
                    case 3:
                        printf("FileNames:\n");
                        for(j=0;j<i;j++){
                            if(files[j].status==1)
                                printf("%d - %s\n",j,files[j].filename);
                        }
                        break;
                    case 4:
                        printf("FileName: ");
                        scanf("%s",temp);
                        for(j=0;j<i;j++){
                            if(strcmp(files[j].filename,temp)==0){
                                printf("\nFoundat: %d",j);
                                break;
                            }
                        }
                        break;
                    case 5:
                        printf("FileName: ");
                        scanf("%s",temp);
                        for(j=0;j<i;j++){
                            if(strcmp(files[j].filename,temp)==0){
                                files[j].status=0;
                                printf("\nDeleted");
                                break;
                            }
                        }
                        break;
                }
            }
            break;
        }
        case 2:{
            int i=0,j;
            char temp[40];
            struct user users[40];
            while(x){
                printf("\nMenu:\n1.CreateUser\n2.RenameUser\n3.DisplayUsers\n4.SearchUser\n5.DeleteUser\n6.OperationsunderaUser\n0.Exit\n");
                scanf("%d",&x);
                switch(x){
                    case 1:
                        printf("UserName: ");
                        scanf("%s",temp);
                        strcpy(users[i].username,temp);
                        users[i].fc=0;
                        users[i].status=1;
                        i++;
                        break;
                    case 2:
                        printf("UserName: ");
                        scanf("%s",temp);
                        for(j=0;j<i;j++){
                            if(strcmp(users[j].username,temp)==0){
                                printf("\nChangeTo: ");
                                scanf("%s",temp);
                                strcpy(users[j].username,temp);
                                break;
                            }
                        }
                        break;
                    case 3:
                        printf("UserNames:\n");
                        for(j=0;j<i;j++){
                            if(users[j].status==1)
                                printf("%d - %s\n",j,users[j].username);
                        }
                        break;
                    case 4:
                        printf("UserName: ");
                        scanf("%s",temp);
                        for(j=0;j<i;j++){
                            if(strcmp(users[j].username,temp)==0){
                                printf("\nFoundat: %d",j);
                                break;
                            }
                        }
                        break;
                    case 5:
                        printf("UserName: ");
                        scanf("%s",temp);
                        for(j=0;j<i;j++){
                            if(strcmp(users[j].username,temp)==0){
                                users[j].status=0;
                                printf("\nDeleted");
                                break;
                            }
                        }
                        break;
                    case 6:
                        printf("UserName: ");
                        scanf("%s",temp);
                        for(j=0;j<i;j++){
                            if(strcmp(users[j].username,temp)==0){
                                int user_choice=1;
                                while(user_choice){
                                    printf("\nOperationsunderuser%s:\n1.CreateFile\n2.RenameFile\n3.DisplayFiles\n4.SearchFile\n5.DeleteFile\n0.Exit\n",users[j].username);
                                    scanf("%d",&user_choice);
                                    switch(user_choice){
                                        case 1:
                                            printf("FileName: ");
                                            scanf("%s",temp);
                                            strcpy(users[j].files[users[j].fc].filename,temp);
                                            users[j].files[users[j].fc].status=1;
                                            users[j].fc++;
                                            break;
                                        case 2:
                                            printf("FileName: ");
                                            scanf("%s",temp);
                                            for(int k=0;k<users[j].fc;k++){
                                                if(strcmp(users[j].files[k].filename,temp)==0){
                                                    printf("\nChangeTo: ");
                                                    scanf("%s",temp);
                                                    strcpy(users[j].files[k].filename,temp);
                                                    break;
                                                }
                                            }
                                            break;
                                        case 3:
                                            printf("FileNames:\n");
                                            for(int k=0;k<users[j].fc;k++){
                                                if(users[j].files[k].status==1)
                                                    printf("%d - %s\n",k,users[j].files[k].filename);
                                            }
                                            break;
                                        case 4:
                                            printf("FileName: ");
                                            scanf("%s",temp);
                                            for(int k=0;k<users[j].fc;k++){
                                                if(strcmp(users[j].files[k].filename,temp)==0){
                                                    printf("\nFoundat: %d",k);
                                                    break;
                                                }
                                            }
                                            break;
                                        case 5:
                                            printf("FileName: ");
                                            scanf("%s",temp);
                                            for(int k=0;k<users[j].status;k++){
                                                if(strcmp(users[j].files[k].filename,temp)==0){
                                                    users[j].files[k].status=0;
                                                    printf("\nDeleted");
                                                    break;
                                                }
                                            }
                                            break;
                                    }
                                }
                            }
                        }
                        break;
                }
            }
            break;
        }
    }
    return 0;
}
