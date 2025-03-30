#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Brasileirao
{
    char nome[100];
    int pontos;
    int jogos;
    int vitorias;
    int empates;
    int derrotas;
    int saldo;
    int golspro;
    int golscontra;
};

int posicao(struct Brasileirao *br, int numtimes, char time[50]) // function to find the team position to calculate the results in the Brasileirao struct
{
    for (int i = 0; i < numtimes; i++) 
    {
        if (strcmp(br[i].nome, time) == 0) 
        {
            return i;
        }
    }
    return 1;
}
void results(struct Brasileirao *br, int numtimes, char casa[50], char fora[50], int gols1, int gols2) // Void function to calculate the results of the matches and save it in the struct
{
        int pos1 = posicao(br, numtimes, casa); // find the position of the home team
        int pos2 = posicao(br, numtimes, fora); // find the position of the away team
        if (gols1 > gols2) // if for when the home team wins
        {
        br[pos1].pontos += 3;
        br[pos1].vitorias += 1;
        br[pos2].derrotas += 1;
        } 
        else if (gols1 < gols2) // if for when the away team wins
        {
        br[pos2].pontos += 3;
        br[pos2].vitorias += 1;
        br[pos1].derrotas += 1;
        } 
        else // if for when the match draw
        {
        br[pos1].pontos += 1;
        br[pos2].pontos += 1;
        br[pos1].empates += 1;
        br[pos2].empates += 1;
        }
        br[pos1].jogos += 1;    // save the home team's supplementary results
        br[pos1].saldo += gols1 - gols2;
        br[pos1].golscontra += gols2;
        br[pos1].golspro += gols1;

        br[pos2].jogos += 1;    // save the away team's supplementary results
        br[pos2].saldo += gols2 - gols1;
        br[pos2].golscontra += gols1;
        br[pos2].golspro += gols2;
}

void ordenarClassificacao(struct Brasileirao *br, int numtimes) // function to organize the table based on tiebreaker criteria
{
    for (int i = 0; i < numtimes - 1; i++) 
    {
        for (int j = 0; j < numtimes - i - 1; j++) 
        {
            int trocar = 0; // variable to trade the position of the teams if true
            if (br[j].pontos < br[j + 1].pontos) // checks whether the score of the team in the lowest position is higher than that of the team in the highest position
            {
                trocar = 1;
            } 
            else if (br[j].pontos == br[j + 1].pontos && br[j].vitorias < br[j + 1].vitorias) // checks whether the score of the team in the lower position is higher than that of the team in the higher position
            {
                trocar = 1;
            }
            else if (br[j].pontos == br[j + 1].pontos && br[j].vitorias == br[j + 1].vitorias && br[j].saldo < br[j + 1].saldo) //  checks if the goal difference of the lower placed team is greater than the higher placed team
            {
                trocar = 1;
            }
            else if (br[j].pontos == br[j + 1].pontos && br[j].vitorias == br[j + 1].vitorias && br[j].saldo == br[j + 1].saldo && br[j].golspro < br[j + 1].golspro) // checks if the lower placed team scored more goals than the higher placed team
            {
                trocar = 1;
            }
            else if (br[j].pontos == br[j + 1].pontos && br[j].vitorias == br[j + 1].vitorias && br[j].saldo == br[j + 1].saldo && br[j].golspro == br[j + 1].golspro && br[j].golscontra > br[j + 1].golscontra) // checks whether the lower placed team conceded fewer goals than the higher placed team
            {
                trocar = 1;
            }
            else if (br[j].pontos == br[j + 1].pontos && br[j].vitorias == br[j + 1].vitorias && br[j].saldo == br[j + 1].saldo && br[j].golspro == br[j + 1].golspro && br[j].golscontra == br[j + 1].golscontra)
            {
                if (strcmp(br[j].nome, br[j + 1].nome) > 0) // sort in alphabetical order in case of a tie in goals conceded
                {
                    trocar = 1;
                }
            }
            if (trocar) // swap the team position from top to bottom
            {
                struct Brasileirao temp = br[j];
                br[j] = br[j + 1];
                br[j + 1] = temp;
            }
        }
    }
}

void exibirClassificacao(struct Brasileirao *br, int numtimes) // displays the final classification
{
    printf("Time Pontos Jogos Vitorias Empates Derrotas Saldo Gols Pro Gols Contra\n");

    for(int i=0;i<numtimes;i++)
    {
        printf("%s %d %d %d %d %d %d %d %d\n",br[i].nome, br[i].pontos, br[i].jogos, br[i].vitorias ,br[i].empates, br[i].derrotas, br[i].saldo, br[i].golspro, br[i].golscontra);
    }
}

int main()
{
    int numtimes;
    scanf("%d", &numtimes); // save the number of teams
    getchar();
    struct Brasileirao *times = (struct Brasileirao *)malloc(numtimes * sizeof(struct Brasileirao)); // Cast
    for (int i = 0; i < numtimes; i++) // initializes the values ​​of the struct
    {
        fgets(times[i].nome, sizeof(times[i].nome), stdin);
        times[i].nome[strcspn(times[i].nome, "\n")] = 0;
        times[i].pontos = 0;
        times[i].jogos = 0;
        times[i].vitorias = 0;
        times[i].empates = 0;
        times[i].derrotas = 0;
        times[i].saldo = 0;
        times[i].golspro = 0;
        times[i].golscontra = 0;
    }
    char casa[50], fora[50];
    int gols1, gols2;
    for (int i = 0; i < numtimes; i++) // saves values ​​in specific variables
    {
        scanf("%s x %s:", casa, fora);
        scanf(" %d x %d", &gols1, &gols2);
        for (int j = 0; j < strlen(fora); j++)
        {
            if (fora[j] == ':')
            {
                fora[j] = '\0';
            }
        }
        
        results(times, numtimes, casa, fora, gols1, gols2); // call the function after each match
    }
    ordenarClassificacao(times, numtimes); // sort the classification according to the criteria
    exibirClassificacao(times, numtimes); // displays the rating on the screen
    
    free(times); // free the memory
    return 0;
}
