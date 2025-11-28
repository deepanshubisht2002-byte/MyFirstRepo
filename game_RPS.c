//Rock Paper Scissors!!!!!!!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char rng();
void result(char ch, char comp, int * ptr);

int pp=0,cp=0;
char name[100];
int main()
{
    char comp;
    char ch;
    printf("\n**********Rock Paper Scissors**********\n");
    printf("Enter the Player's name : ");
    scanf("%s",&name);
    getchar();
    printf("\n%s vs. Computer \n",name);
    for (int i=1;i<=3;i++)
    {
        printf("\n----Turn %d----\n",i);
        printf("Enter your choice Rock(R)/Paper(P)/Scissor(S) : ");
        scanf("%c",&ch);
        getchar();
        switch (ch)
        {
        case 'R':
            printf("\n%s chooses Rock\n",name);
            break;
        case 'P':
            printf("\n%s chooses Paper\n",name);
            break;
        case 'S':
            printf("\n%s chooses Scissor\n",name);
            break;
        default:
            printf("Invalid Input!!!, Try again\n");
            i-=1;
            continue;
        }
        comp=rng();
        switch (comp)
        {
        case 'R':
            printf("Computer chooses Rock\n");
            break;
        case 'P':
            printf("Computer chooses Paper\n");
            break;
        case 'S':
            printf("Computer chooses Scissor\n");
            break;
        }
        result(ch,comp,&i);
        printf("%s's Score : %d\n",name,pp);
        printf("Computer's Score : %d\n",cp);
        printf("\n");
    }
    if (pp>cp)
    {
        printf("\n*********%s Wins the Game!!!*********\n",name);
    }
    else if (pp<cp)
    {
        printf("\n******Computer Wins the Game!!!******\n",name);
    }
    printf("\nThanKs for Playing %s",name);
    return 0;
}

char rng()
{
    srand(time(NULL));
    switch (rand()%3)
    {
    case 0:
        return 'R';
        break;
    case 1:
        return 'P';
        break;
    case 2:
        return 'S';
        break;
    }
}

void result(char ch, char comp, int *ptr)
{
    switch (ch)
    {
    case 'R':
        switch (comp)
        {
        case 'R':
            printf("\nThats a Draw!!, Try again\n");
            (*ptr)--;
            break;
        case 'P':
            printf("\nComputer Wins!\n",name);
            cp++;
            break;
        case 'S':
            printf("\n%s Wins!\n",name);
            pp++;
            break;
        }
        break;
    case 'P':
        switch (comp)
        {
        case 'P':
            printf("\nThats a Draw!!, Try again\n");
            (*ptr)--;
            break;
        case 'S':
            printf("\nComputer Wins!\n",name);
            cp++;
            break;
        case 'R':
            printf("\n%s Wins!\n",name);
            pp++;
            break;
        }
        break;
    case 'S':
        switch (comp)
        {
        case 'S':
            printf("\nThats a Draw!!, Try again\n");
            (*ptr)--;
            break;
        case 'R':
            printf("\nComputer Wins!\n",name);
            cp++;
            break;
        case 'P':
            printf("\n%s Wins!\n",name);
            pp++;
            break;
        }
        break;
    }
}
