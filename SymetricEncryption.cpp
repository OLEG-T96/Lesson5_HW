#include <iostream>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace {
  static constexpr unsigned key{10};
};
static void Encrypt(string &Umessage)
{
    unsigned Msize = Umessage.length();
    char buf[key][key]{};
    unsigned pos = 0;
    for(unsigned i = 0; i < ((Msize/key)); ++i)
       {
         for(unsigned j = 0; j < key ; ++j)
            {
                {
                  buf[i][j] = Umessage[pos];
                  ++pos;
                }
            }
       }


    if(pos < Msize )
      {
        for(unsigned j = 0; j < (Msize % key); ++j)
           {
             buf[(Msize/key)][j] = Umessage[pos];
             ++pos;
           }
    }

      pos = 0;
    for(unsigned j = 0; j < (Msize % key); ++j)
       {
         for(unsigned i = 0; i < ((Msize/key) + 1); ++i)
            {
                {
                  Umessage[pos] =  buf[i][j];
                  ++pos;
                }
            }
        }

    for(unsigned j = (Msize % key); j < key; ++j)
       {
         for(unsigned i = 0; i < (Msize/key); ++i)
            {
                {
                  Umessage[pos] =  buf[i][j];

                  ++pos;
                }
            }
        }
}

static void Decrypt(string &Umessage)
{
    unsigned Msize = Umessage.length();
    char buf[key][key]{};
    unsigned pos = 0;
      pos = 0;
    for(unsigned j = 0; j < (Msize % key); ++j)
       {
         for(unsigned i = 0; i < ((Msize/key) + 1); ++i)
            {
                {
                buf[i][j] = Umessage[pos];
                  ++pos;
                }
            }
        }

    for(unsigned j = (Msize % key); j < key; ++j)
       {
         for(unsigned i = 0; i < (Msize/key); ++i)
            {
                {
                buf[i][j] = Umessage[pos];

                  ++pos;
                }
            }
        }

     pos = 0;
    for(unsigned i = 0; i < ((Msize/key)); ++i)
       {
         for(unsigned j = 0; j < key ; ++j)
            {
                {
                   Umessage[pos] = buf[i][j];
                  ++pos;

                }
            }
       }

    if(pos < Msize )
      {
        for(unsigned j = 0; j < (Msize % key); ++j)
           {
              Umessage[pos] = buf[(Msize/key)][j];
             ++pos;
           }
    }
}

int main()
{
    cout<< "Enter your message\n" << "> ";
    std::string Umessage;
    UserInput:
    std::getline(cin,Umessage);
    unsigned Msize = Umessage.length();

    if(Msize > (( key * key ) - 1) )
      {
        cout<< "Your message should be less than 99 symbols ";
        cout<< endl << "Try Again\n" << "> ";
        goto UserInput;
      }
    else if(Msize < key)
      {
        cout<< "Your message should be more than 20 symbols ";
        cout<< endl << "Try Again\n" << "> ";
        goto UserInput;
      }

    Encrypt(Umessage);
    cout<< endl << "Encrypted Message:\n >" << Umessage << endl;
    Decrypt(Umessage);
    cout<< endl << "Decrypted Message:\n >" << Umessage << endl;

    return 0;
}
