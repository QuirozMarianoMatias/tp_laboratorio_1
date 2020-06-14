#include "input.h"




int getString(char* msg, char* msgError, int mini, int maxi, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[maxi+10];

    if(msg!=NULL && msgError!=NULL && mini<=maxi && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            gets(bufferStr);


            if(strlen(bufferStr)>=mini && strlen(bufferStr)<maxi)
            {
                strcpy(resultado,bufferStr);
                retorno=0;
                break;
            }
            printf("%s",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}


int getName (char* msg, char* msgError, int mini, int maxi, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[maxi];

    if(msg!=NULL && msgError!=NULL && mini<=maxi && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,mini,maxi,&reintentos,bufferStr)) //
            {
                if(isValidName(bufferStr)==1)
                {
                    strcpy(resultado,bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidName(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if((stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a' && stringRecibido[i]) || stringRecibido[i]>'z')&& stringRecibido[i]!=' ')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}


int getInt (char* msg,char* msgError,int minSize,int maxSize,int reintentos,int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidNumber(bufferStr)==1)
                {
                    *input=atoi(bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


int isValidNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}



int getFloat(char* msg, char* msgError, int minSize, int maxSize, int reintentos, float* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidFloatNumber(bufferStr)==1)
                {
                    *input=atof(bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidFloatNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    int flag = 0;

    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9' )
        {
            if (stringRecibido[i]=='.' && flag ==0)
            {
                flag = 1;
                continue;

            }
            retorno=0;
            break;
        }
    }
    return retorno;
}

int getPatente (char* msg, char* msgError, int mini, int maxi, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[maxi];

    if(msg!=NULL && msgError!=NULL && mini<=maxi && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,mini,maxi,&reintentos,bufferStr)) //
            {
                if(isValedPatente(bufferStr)==1)
                {
                    strcpy(resultado,bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValedPatente (char* stringRecibido)
{
    int i;
    int j;
    int retorno = 1;


    for (i=0 ; i<3; i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno = 0;
            break;
        }

    }

    for (j=3; stringRecibido[j]!= '\0'; j++)
    {
        if(stringRecibido[j]<'A' || (stringRecibido[j]>'Z' && stringRecibido[j]<'a' ) || stringRecibido[j]>'z')
        {
            retorno=0;
            break;
        }
    }

    return retorno;
}


int getSex (char* msg, char* msgError, int mini, int maxi, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[maxi];

    if(msg!=NULL && msgError!=NULL && mini<=maxi && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,mini,maxi,&reintentos,bufferStr))
            {
                if(isValidSex(bufferStr)==1)
                {
                    *resultado = bufferStr [0];
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidSex (char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if(stringRecibido[0]!= 'F'  && stringRecibido[0]!= 'M' && stringRecibido[0]!= 'f' && stringRecibido[0]!= 'm' )
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
