#include "Message.h"

#include<iostream>
#include<string>
Message::Message()
{
    this->setDecrypted("");
    this->setEncrypted("");
    this->setKey("");
}

bool Message::verifyKey(string *key)
{
    for (string::iterator it = (*key).begin(); it != (*key).end(); it++)
    {
        if( *it >= 65 && *it <= 90 )
            *it = *it + 32;
        else if( !(*it >= 97 && *it <= 122) && *it != 32 )
            return false;
    }
    return true;
}
void Message::Encrypt()
{
    char cAux, a, b;
    bool bAux;
    if(this->getKey() == "" || this->getDecrypted() == "")
        return;
    for(int i=0, j=0; i < getDecrypted().length(); i++)
    {
        bAux = false;
        cAux = getDecrypted()[i];
        if( cAux >= 65 && cAux <= 90)
        {
            a = 65;
            b = 90;
            bAux = true;
            cAux = getKey()[j] - 32;
        }
        else if( cAux >= 97 && cAux <= 122)
        {
            a = 97;
            b = 122;
            bAux = true;
            cAux = getKey()[j];
        }
        if (bAux)
        {
            cAux += getDecrypted()[i] - a;
            if(cAux > b)
                cAux -= 26;
            j++;
            if(j == this->getKey().length())
                j = 0;
        }
        setEncrypted(getEncrypted() + cAux);
    }
}
void Message::Decrypt()
{

}

string Message::getDecrypted()
{
    return this->decrypted;
}
void Message::setDecrypted(string decrypted)
{
    this->decrypted = decrypted;
}
string Message::getEncrypted()
{
    return this->encrypted;
}
void Message::setEncrypted(string encrypted)
{
    this->encrypted = encrypted;
}
string Message::getKey()
{
    return this->key;
}
bool Message::setKey(string key)
{
    if(this->verifyKey(&key))
        this->key = key;
    else
        return 0;
    return 1;
}
