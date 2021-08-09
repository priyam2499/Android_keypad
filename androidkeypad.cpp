#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include <cstring>
#include <map>
#include <iterator>
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std;
template<typename T>
class Node
{
public:
string key;
T value;
Node<T>*next;
Node(string key,T val)
{
this->key=key;
value=val;
next=NULL;
}
~Node()
{
if(next!=NULL)
{
delete next;
}
}
};
/*template<typename T>
class Hashtable
{
Node<T>**table;
int current_size;
int table_size;
int hashfn(string key)
{
int idx=0;
int p=1;
for(int j=0;j<key.length();j++)
{
idx=idx+(key[j]*p)%table_size;
idx=idx%table_size;
p=(p*27)%table_size;
}
return idx;
}
public:
void rehash()
{
Node<T>** oldTable=table;
int oldTableSize=table_size;
table_size=2*table_size;
table=new Node<T>*[table_size];
for(int i=0;i<table_size;i++)
{
table[i]=NULL;
}
current_size=0;
for(int i=0;i<oldTableSize;i++)
{
Node<T>*temp=oldTable[i];
while(temp!=NULL)
{
insert(temp->key,temp->value);
temp=temp->next;
}
if(oldTable[i]!=NULL)
{
delete oldTable[i];
}
}
delete [] oldTable;
}
Hashtable(int ts=7)
{
table_size=ts;
table=new Node<T>*[table_size];
current_size =0;
for(int i=0;i<table_size;i++)
{
table[i]=NULL;
}
}
void insert(string key,T value)
{
float load_factor = 0;
int index=hashfn(key);
Node<T>*n=new Node<T>(key,value);
n->next=table[index];
table[index]=n;
current_size++;
load_factor=current_size/(table_size);
if(load_factor>0.7)
{
rehash();
}
}
void print()
{
for(int i=0;i<table_size;i++)
{
cout<<"CONTACT_NO"<<i<<"->";
Node<T>*temp=table[i];
while(temp!=NULL)
{
cout<<temp->key<<"->"<<temp->value<<endl;
temp=temp->next;
}
cout<<endl;
}
}
};*/
//search by alphabets
struct TrieNode
{
struct TrieNode *children[ALPHABET_SIZE];
bool isLeaf;
};
struct TrieNode *getNode(void)
{
struct TrieNode *pNode = new TrieNode;
if (pNode)
{
int i;
pNode->isLeaf = false;
for (i = 0; i < ALPHABET_SIZE; i++)
pNode->children[i] = NULL;
}
return pNode;
} ;
void insert(struct TrieNode *root, string key)
{
int length = key.length();
int index;
struct TrieNode *pCrawl = root;
for (int level = 0; level < length; level++)
{
index = CHAR_TO_INDEX(key[level]);
if (!pCrawl->children[index])
pCrawl->children[index] = getNode();
pCrawl = pCrawl->children[index];
}
pCrawl->isLeaf = true;
}
int countChildren(struct TrieNode *node, int *index)
{
int count = 0;
for (int i=0; i<ALPHABET_SIZE; i++)
{
if (node->children[i] != NULL)
{
count++;
*index = i;
}
}
return (count);
}
string walkTrie(struct TrieNode *root)
{
struct TrieNode *pCrawl = root;
int index;
string prefix;
while (countChildren(pCrawl, &index) == 1 &&
pCrawl->isLeaf == false)
{
pCrawl = pCrawl->children[index];
prefix.push_back('a'+index);
}
return (prefix);
}
void constructTrie(string arr[], int n, struct TrieNode *roo
t)
{
for (int i = 0; i < n; i++)
insert (root, arr[i]);
return;
}
string commonPrefix(string arr[], int n)
{
struct TrieNode *root = getNode();
constructTrie(arr, n, root);
return walkTrie(root);
}
//search by digit
int digit=0;
char keypad[]
[5]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"
};
void printbydigit(char*in,char*out){
int index=0;
for(int i=0;i<strlen(in);i++){
int val=in[i]-'0';
cout<<"no is : "<<val<<endl;
//cout<<"str is : "<<keypad[i][0]<<endl;
for(int j=0;j<strlen(keypad[val]);j++){
out[index]=keypad[val][j];
cout<<"out "<<index<<" is : "<<out[index]<<endl;
index++;
}
}
}
//code to find when the last two digits are missing of phone
no.
void findPhoneNumber(int n)
{
int temp = n;
int sum;
while (temp != 0)
{
sum += temp % 10;
temp = temp / 10;
}
if(sum < 10)
cout << n << "0" << sum<<endl;
else
cout << n << sum<<endl;
}
void intro(){
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" .|:|oooooooooooo|:|."<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d888|:|888888888888|:|888b"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d88888|:|888888888888|:|88888b"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d88888888\\:\\8888888888/:/88888888b"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d8888888888'|:|________|:|'8888888888b"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d888888888' |:| |:| '888888888b"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d888888888 |:|________|:| 888888888b"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<"d8888888888b .d888888888888b. d8888888888b"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<"d888888888b') 8888888888888888 ('d888888888b"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<"d888888b'.-'8888888888888888888b`-.'d888888b"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d88'_.-' d88888b''______`'d88888b `-._'88b/"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" `-' d888b' .-' _ _`-. 'd888b `-' //"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d88b' .' _ (3) (2) _`.'d88b //"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" 88/ / (4) (1)_\\ \\88 //"<<end
l;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" 88| | _ .d8b. ==' `| |88 //"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" 88| | (5) 88888 (O) | |88 //"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" 88| | _ 'd8b' _ | |88 \\"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" .88\\ \\ (6) _ _ (9) / /88. //"<<endl
;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d888b. `. (7) (8) .' .d888b \\"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d888888b. `-.______.-' .d888888b //"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" 88888888888q.________.p88888888888 _//"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" 888888888888888888888888888888888888-'"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" d888888888888888888888888888888888888b "<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t";
cout<<" 00000000000000000000000000000000000000"<<endl;
}
void contacts(){
cout<<" _____ _______
_____ _____ _____
_____ _____ _____ "<<e
ndl;
cout<<" /\\ \\ /::\\ \\
/\\ \\ /\\ \\ /\\ \
\ /\\ \\ /\\ \\
/\\ \\ "<<endl;
cout<<" /::\\ \\ /::::\\ \\
/::\\____\\ /::\\ \\ /::\\
\\ /::\\ \\ /::\\ \\
/::\\ \\ "<<endl;
cout<<" /::::\\ \\ /::::::\\ \\
/::::| | \\ ::\\ \\ /::::\\
\\ /::::\\ \\ \\ ::\\ \\
/::::\\ \\ "<<endl;
cout<<" /::::::\\ \\ /::::::::\\ \\
/:::::| | \\ ::\\ \\ /::::::\\
\\ /::::::\\ \\ \\ ::\\ \\ /
::::::\\ \\ "<<endl;
cout<<" /:::/\\ ::\\ \\ /:::/~~\\ ::\\ \\
/::::::| | \\ ::\\ \\ /:::/\\ ::\
\ \\ /:::/\\ ::\\ \\ \\ ::\\ \\
/:::/\\ ::\\ \\ "<<endl;
cout<<" /:::/ \\ ::\\ \\ /:::/ \\ ::\\ \\
/:::/|::| | \\ ::\\ \\ /:::/__\\ ::
\\ \\ /:::/ \\ ::\\ \\ \\ ::\\ \\
/:::/__\\ ::\\ \\ "<<endl;
cout<<" /:::/ \\ ::\\ \\ /:::/ / \\ ::\\ \\
/:::/ |::| | /::::\\ \\ /::::\\ \\ :
:\\ \\ /:::/ \\ ::\\ \\ /::::\\ \\
\\ ::\\ \\ ::\\ \\ "<<endl;
cout<<" /:::/ / \\ ::\\ \\ /:::/____/ \\ ::\\
____\\ /:::/ |::| | _____ /::::::\\ \\ /::::::\\
\\ ::\\ \\ /:::/ / \\ ::\\ \\ /::::::\\ \
\ ___\\ ::\\ \\ ::\\ \\ "<<endl;
cout<<" /:::/ / \\ ::\\ \\|:::| | |:::| |/
:::/ |::| |/\\ \\ /:::/\\:::\\ \\ /:::/\\ ::\\
\\ ::\\ \\ /:::/ / \\ ::\\ \\ /:::/\\ ::\\ \\
/\\ \\ ::\\ \\ ::\\ \\ "<<endl;
cout<<"/:::/____/ \\ ::\\ ___|:::|____| |:::| /::
/ |::| /::\\ ___\\/:::/ \\ ::\\ ___/:::/ \\ ::\\ \\
::\\ ___/:::/____/ \\ ::\\ ___\\/:::/ \\ ::\\ ___/::\\
\\ ::\\ \\ ::\\____\\ "<<endl;
cout<<"\\:::\\ \\ \\::/ /\\:::\\ \\ /:::/
/\\::/ /|::| /:::/ /:::/ \\::/ \\::/ \\:::\\
/:::/ \\:::\\ \\ \\::/ /:::/ \\::/ \\::
:\\ \\:::\\ \\::/ /"<<endl;
cout<<" \\:::\\ \\ \\/____/ \\:::\\ \\ /:::/
/ \\/____/ |::| /:::/ /:::/ / \\/____/ \\/____/ \\:::
\\/:::/ / \\:::\\ \\ \\/____/:::/ / \\/____/ \
\:::\\ \\:::\\ \\/____/ "<<endl;
cout<<" \\:::\\ \\ \\:::\\ /:::/ /
|::|/:::/ /:::/ / \\::::::/
/ \\:::\\ \\ /:::/ / \\:::\\
\\:::\\ \\ "<<endl;
cout<<" \\:::\\ \\ \\:::\\__/:::/ /
|::::::/ /:::/ / \\::::/
/ \\:::\\ \\ /:::/ / \\:::\\
\\:::\\____\\ "<<endl;
cout<<" \\:::\\ \\ \\::::::::/ /
|:::::/ /\\::/ / /:::/
/ \\:::\\ \\ \\::/ / \\:::\\
/:::/ / "<<endl;
cout<<" \\:::\\ \\ \\::::::/ /
|::::/ / \\/____/ /:::/ /
\\:::\\ \\ \\/____/ \\:::\\
/:::/ / "<<endl;
cout<<" \\:::\\ \\ \\::::/ /
/:::/ / /:::/ /
\\:::\\ \\ \\::::::
/ / "<<endl;
cout<<" \\:::\\____\\ \\::/____/
/:::/ / /:::/ /
\\:::\\____\\ \\::::/
/ "<<endl;
cout<<" \\::/ / ~~
\\::/ / \\::/ /
\\::/ / \\::/
/ "<<endl;
cout<<" \\/____/
\\/____/ \\/____/
\\/____/ \\/____/
"<<endl;
}
void alpha()
{
cout<<" _____
_____ _____ _____
_____ _____ "<<endl;
cout<<" /\\ \\
/\\ \\ /\\ \\ /\\
\\ /\\ \\ /\\ \\ "<
<endl;
cout<<" /::\\ \\
/::\\ \\ /::\\ \\ /::\
\ \\ /::\\ \\ /::\\____\\
"<<endl;
cout<<" /::::\\ \\
/::::\\ \\ /::::\\ \\ /::::
\\ \\ /::::\\ \\ /:::/ / "
<<endl;
cout<<" /::::::\\ \\
/::::::\\ \\ /::::::\\ \\ /:::::
:\\ \\ /::::::\\ \\ /:::/ / "<<
endl;
cout<<" /:::/\\:::\\ \\
/:::/\\:::\\ \\ /:::/\\:::\\ \\ /:::
/\\:::\\ \\ /:::/\\:::\\ \\ /:::/ /
"<<endl;
cout<<" /:::/__\\:::\\ \\
/:::/__\\:::\\ \\ /:::/__\\:::\\ \\ /:::/
__\\:::\\ \\ /:::/ \\:::\\ \\ /:::/____/
"<<endl;
cout<<" \\:::\\ \\:::\\ \\
/::::\\ \\:::\\ \\ /::::\\ \\:::\\ \\ /:
:::\\ \\:::\\ \\ /:::/ \\:::\\ \\ /::::\\
\\ "<<endl;
cout<<" ___\\:::\\ \\:::\\ \\
/::::::\\ \\:::\\ \\ /::::::\\ \\:::\\ \\ /::
::::\\ \\:::\\ \\ /:::/ / \\:::\\ \\ /::::::\
\ \\ _"<<endl;
cout<<" /\\ \\:::\\ \\:::\\ \
\ /:::/\\:::\\ \\:::\\ \\ /:::/\\:::\\ \\:::\\ \\
/:::/\\:::\\ \\:::\\____\\ /:::/ / \\:::\\ \\ /:::
/\\:::\\ \\ /\\ \\ "<<endl;
cout<<" /::\\ \\:::\\ \\:::\\
____/:::/__\\:::\\ \\:::\\____/:::/ \\:::\\ \\:::\\
____/:::/ \\:::\\ \\:::| /:::/____/ \\:::\\
____/:::/ \\:::\\ /::\\____\\ "<<endl;
cout<<" \\:::\\ \\:::\\ \\::/ \
\:::\\ \\:::\\ \\::/ \\::/ \\:::\\ /:::/ \\::/
|::::\\ /:::|____\\:::\\ \\ \\::/ \\::/ \\:
::\\ /:::/ / "<<endl;
cout<<" \\:::\\ \\:::\\ \\/____/
\\:::\\ \\:::\\ \\/____/ \\/____/ \\:::\\/:::/ / \\/
____|:::::\\/:::/ / \\:::\\ \\ \\/____/ \\/____/
\\:::\\/:::/ / "<<endl;
cout<<" \\:::\\ \\:::\\ \\
\\:::\\ \\:::\\ \\ \\::::::/ / |
:::::::::/ / \\:::\\ \\ \\:::::
:/ / "<<endl;
cout<<" \\:::\\ \\:::\\____\\
\\:::\\ \\:::\\____\\ \\::::/ /
|::|\\::::/ / \\:::\\ \\ \\::
::/ / "<<endl;
cout<<" \\:::\\ /:::/ /
\\:::\\ \\::/ / /:::/ / |::| \
\::/____/ \\:::\\ \\ /:::/ /
"<<endl;
cout<<" \\:::\\/:::/ /
\\:::\\ \\/____/ /:::/ / |::|
~| \\:::\\ \\ /:::/ /
"<<endl;
cout<<" \\::::::/ /
\\:::\\ \\ /:::/ / |::|
| \\:::\\ \\ /:::/ /
"<<endl;
cout<<" \\::::/ /
\\:::\\____\\ /:::/ / \\::|
| \\:::\\____\\ /:::/ /
"<<endl;
cout<<" \\::/ /
\\::/ / \\::/ / \\:|
| \\::/ / \\::/ /
"<<endl;
cout<<" \\/____/
\\/____/ \\/____/ _____ \\|
____ \\/____/ \\/____/
"<<endl;
cout<<"
/\\ \\ |\\
\\ "<<endl;
cout<<"
/::\\ \\ |:\\
____\\ "<<endl ;
cout<<"
/::::\\ \\ |::|
| "<<endl ;
cout<<"
/::::::\\ \\ |::|
| "<<endl ;
cout<<"
/:::/\\:::\\ \\ |::|
| "<<endl ;
cout<<"
/:::/__\\:::\\ \\ |::|
| "<<endl ;
cout<<"
/::::\\ \\:::\\ \\ |::|
| "<<endl ;
cout<<"
/::::::\\ \\:::\\ \\ |::|
___|______ "<<endl ;
cout<<"
/:::/\\:::\\ \\:::\\ ___\\ /::
::::::\\ \\ "<<endl ;
cout<<"
/:::/__\\:::\\ \\:::| |/:::::
:::::\\____\\ "<<endl;
cout<<"
\\:::\\ \\:::\\ /:::|____/:::/
~~~~/~~/____/ "<<endl ;
cout<<"
\\:::\\ \\:::\\/:::/ /:::/
/ "<<endl ;
cout<<"
\\:::\\ \\::::::/ /:::/
/ "<<endl;
cout<<"
\\:::\\ \\::::/ /:::/ /
"<<endl;
cout<<"
\\:::\\ /:::/ /\\::/ /
"<<endl ;
cout<<"
\\:::\\/:::/ / \\/____/
"<<endl;
cout<<"
\\::::::/ /
"<<endl ;
cout<<"
\\::::/ /
"<<endl ;
cout<<"
\\::/____/
"<<endl ;
cout<<"
"<<endl;
cout<<"
"<<endl;
cout<<" _____ _____ __
___ _____ _____
_____ _____ _____
_____ "<<endl;
cout<<" /\\ \\ /\\ \\
/\\ \\ /\\ \\ /\\ \
\ /\\ \\ /\\ \\
/\\ \\ /\\ \\ "<<endl ;
cout<<" /::\\ \\ /::\\
____\\/::\\ \\ /::\\____\\ /:
:\\ \\ /::\\ \\ /::\\ \
\ /::\\ \\ /::\\ \\ "<<endl ;
cout<<" /::::\\ \\ /:::/ /::
::\\ \\ /:::/ / /::::\\ \\
/::::\\ \\ /::::\\ \\ \\
:::\\ \\ /::::\\ \\ "<<endl ;
cout<<" /::::::\\ \\ /:::/ /:::
:::\\ \\ /:::/ / /::::::\\ \
\ /::::::\\ \\ /::::::\\ \\
\\:::\\ \\ /::::::\\ \\ "<<endl ;
cout<<" /:::/\\:::\\ \\ /:::/ /:::
/\\:::\\ \\ /:::/ / /:::/\\:::\\
\\ /:::/\\:::\\ \\ /:::/\\:::\\ \\
\\:::\\ \\ /:::/\\:::\\ \\ "<<endl ;
cout<<" /:::/__\\:::\\ \\ /:::/ /:::/
__\\:::\\ \\ /:::/____/ /:::/__\\:::\\
\\ /:::/__\\:::\\ \\ /:::/__\\:::\\ \\
\\:::\\ \\ /:::/__\\:::\\ \\ "<<endl ;
cout<<" /::::\\ \\:::\\ \\ /:::/ /::::
\\ \\:::\\ \\ /::::\\ \\ /::::\\ \
\:::\\ \\ /::::\\ \\:::\\ \\ /::::\\ \\:::
\\ \\ /::::\\ \\ \\:::\\ \\:::\\ \\ "
<<endl ;
cout<<" /::::::\\ \\:::\\ \\ /:::/ /:::::
:\\ \\:::\\ \\ /::::::\\ \\ _____ /::::::\\
\\:::\\ \\ /::::::\\ \\:::\\ \\ /::::::\\ \\::
:\\ \\ /::::::\\ \\ ___\\:::\\ \\:::\\ \\ "
<<endl ;
cout<<" /:::/\\:::\\ \\:::\\ \\ /:::/ /:::/\
\:::\\ \\:::\\____\\ /:::/\\:::\\ \\ /\\ \\ /:::/\\:
::\\ \\:::\\ \\ /:::/\\:::\\ \\:::\\ ___\\ /:::/\\:::
\\ \\:::\\ \\ /:::/\\:::\\ \\ /\\ \\:::\\ \\:::
\\ \\ "<<endl ;
cout<<" /:::/ \\:::\\ \\:::\\____/:::/____/:::/ \
\:::\\ \\:::| /:::/ \\:::\\ /::\\____/:::/ \\:::\\
\\:::\\____/:::/__\\:::\\ \\:::| /:::/__\\:::\\ \\:
::\\____\\/:::/ \\:::\\____/::\\ \\:::\\ \\:::\\____\\
"<<endl ;
cout<<" \\::/ \\:::\\ /:::/ \\:::\\ \\::/
\\:::\\ /:::|____\\::/ \\:::\\ /:::/ \\::/ \\:::
\\ /:::/ \\:::\\ \\:::\\ /:::|____\\:::\\ \\:::\\
\\::/ /:::/ \\::/ \\:::\\ \\:::\\ \\::/ /"<<
endl ;
cout<<" \\/____/ \\:::\\/:::/ / \\:::\\ \\/
_____/\\:::\\/:::/ / \\/____/ \\:::\\/:::/ / \\/____/
\\:::\\/:::/ / \\:::\\ \\:::\\/:::/ / \\:::\\ \\::
:\\ \\/____/:::/ / \\/____/ \\:::\\ \\:::\\ \\/
____/ "<<endl ;
cout<<" \\::::::/ / \\:::\\ \\
\\::::::/ / \\::::::/ / \\::::::/
/ \\:::\\ \\::::::/ / \\:::\\ \\:::\\ \\ /
:::/ / \\:::\\ \\:::\\ \\ "<<endl ;
cout<<" \\::::/ / \\:::\\ \\
\\::::/ / \\::::/ / \\::::/
/ \\:::\\ \\::::/ / \\:::\\ \\:::\\
____\\/:::/ / \\:::\\ \\:::\\____\\ "<<e
ndl ;
cout<<" /:::/ / \\:::\\ \\
\\::/____/ /:::/ / /:::/ /
\\:::\\ /:::/ / \\:::\\ \\::/ /\\::/
/ \\:::\\ /:::/ / "<<endl ;
cout<<" /:::/ / \\:::\\ \\
~~ /:::/ / /:::/ /
\\:::\\/:::/ / \\:::\\ \\/____/ \\/____/
\\:::\\/:::/ / "<<endl ;
cout<<" /:::/ / \\:::\\ \\
/:::/ / /:::/ /
\\::::::/ / \\:::\\ \\
\\::::::/ / "<<endl ;
cout<<" /:::/ / \\:::\\____\\
/:::/ / /:::/ /
\\::::/ / \\:::\\____\\
\\::::/ / "<<endl ;
cout<<" \\::/ / \\::/ /
\\::/ / \\::/ /
\\::/____/ \\::/ /
\\::/ / "<<endl ;
cout<<" \\/____/ \\/____/
\\/____/ \\/____/
~~ \\/____/
\\/____/ "<<endl ;
}
void digits()
{
cout<<" _____
_____ _____ _____
_____ _____ "<<endl;
cout<<" /\\ \\
/\\ \\ /\\ \\ /\\
\\ /\\ \\ /\\ \\
"<<endl;
cout<<" /::\\ \\
/::\\ \\ /::\\ \\ /::\\
\\ /::\\ \\ /::\\____\\
"<<endl;
cout<<" /::::\\ \\
/::::\\ \\ /::::\\ \\ /::::\
\ \\ /::::\\ \\ /:::/ /
"<<endl;
cout<<" /::::::\\ \\
/::::::\\ \\ /::::::\\ \\ /::::::
\\ \\ /::::::\\ \\ /:::/ /
"<<endl;
cout<<" /:::/\\:::\\ \\
/:::/\\:::\\ \\ /:::/\\:::\\ \\ /:::/
\\:::\\ \\ /:::/\\:::\\ \\ /:::/ /
"<<endl;
cout<<" /:::/__\\:::\\ \\
/:::/__\\:::\\ \\ /:::/__\\:::\\ \\ /:::/
__\\:::\\ \\ /:::/ \\:::\\ \\ /:::/____/
"<<endl;
cout<<" \\:::\\ \\:::\\ \\
/::::\\ \\:::\\ \\ /::::\\ \\:::\\ \\ /::
::\\ \\:::\\ \\ /:::/ \\:::\\ \\ /::::\\
\\ "<<endl;
cout<<" ___\\:::\\ \\:::\\ \\
/::::::\\ \\:::\\ \\ /::::::\\ \\:::\\ \\ /:::
:::\\ \\:::\\ \\ /:::/ / \\:::\\ \\ /::::::\\
\\ _____ "<<endl;
cout<<" /\\ \\:::\\ \\:::\\ \\
/:::/\\:::\\ \\:::\\ \\ /:::/\\:::\\ \\:::\\ \\ /:
::/\\:::\\ \\:::\\____\\ /:::/ / \\:::\\ \\ /:::/\
\:::\\ \\ /\\ \\ "<<endl;
cout<<" /::\\ \\:::\\ \\:::\\
____/:::/__\\:::\\ \\:::\\____/:::/ \\:::\\ \\:::\\
____/:::/ \\:::\\ \\:::| /:::/____/ \\:::\\
____/:::/ \\:::\\ /::\\____\\"<<endl;
cout<<" \\:::\\ \\:::\\ \\::/ \
\:::\\ \\:::\\ \\::/ \\::/ \\:::\\ /:::/ \\::/
|::::\\ /:::|____\\:::\\ \\ \\::/ \\::/ \\:
::\\ /:::/ /"<<endl;
cout<<" \\:::\\ \\:::\\ \\/____/
\\:::\\ \\:::\\ \\/____/ \\/____/ \\:::\\/:::/ / \\/
____|:::::\\/:::/ / \\:::\\ \\ \\/____/ \\/____/
\\:::\\/:::/ / "<<endl;
cout<<" \\:::\\ \\:::\\ \\
\\:::\\ \\:::\\ \\ \\::::::/ / |
:::::::::/ / \\:::\\ \\ \\:::::
:/ / "<<endl;
cout<<" \\:::\\ \\:::\\____\\
\\:::\\ \\:::\\____\\ \\::::/ / |
::|\\::::/ / \\:::\\ \\ \\:::
:/ / "<<endl;
cout<<" \\:::\\ /:::/ /
\\:::\\ \\::/ / /:::/ / |::| \
\::/____/ \\:::\\ \\ /:::/ /
"<<endl;
cout<<" \\:::\\/:::/ /
\\:::\\ \\/____/ /:::/ / |::| ~
| \\:::\\ \\ /:::/ /
"<<endl;
cout<<" \\::::::/ /
\\:::\\ \\ /:::/ / |::| |
\\:::\\ \\ /:::/ /
"<<endl;
cout<<" \\::::/ /
\\:::\\____\\ /:::/ / \\::|
| \\:::\\____\\ /:::/ /
"<<endl;
cout<<" \\::/ /
\\::/ / \\::/ / \\:| |
\\::/ / \\::/ / "
<<endl;
cout<<" \\/____/
\\/____/ \\/____/ _____ \\|
_____ \\/____/ \\/____/
"<<endl;
cout<<"
/\\ \\ |\\
\\ "<
<endl;
cout<<"
/::\\ \\ |:\\
____\\
"<<endl;
cout<<"
/::::\\ \\ |::|
| "<<e
ndl;
cout<<"
/::::::\\ \\ |::|
| "<<e
ndl;
cout<<"
/:::/\\:::\\ \\ |::|
| "<<e
ndl;
cout<<"
/:::/__\\:::\\ \\ |::|
| "<<e
ndl;
cout<<"
/::::\\ \\:::\\ \\ |::|
| "<<
endl;
cout<<"
/::::::\\ \\:::\\ \\ |::|
___|______ "
<<endl;
cout<<"
/:::/\\:::\\ \\:::\\ ___\\ /:::
:::::\\ \\
"<<endl;
cout<<"
/:::/__\\:::\\ \\:::| |/::::::
::::\\____\\ "
<<endl;
cout<<"
\\:::\\ \\:::\\ /:::|____/:::/
~~~~/~~
"<<endl;
cout<<"
\\:::\\ \\:::\\/:::/ /:::/
/ "<<
endl;
cout<<"
\\:::\\ \\::::::/ /:::/ /
"<<e
ndl;
cout<<"
\\:::\\ \\::::/ /:::/ /
"<<e
ndl;
cout<<"
\\:::\\ /:::/ /\\::/ /
"<<e
ndl;
cout<<"
\\:::\\/:::/ / \\/____/
"<<e
ndl;
cout<<"
\\::::::/ /
"<<end
l;
cout<<"
\\::::/ /
"<<end
l;
cout<<"
\\::/____/
"<<end
l;
cout<<" _____
_____ ~_____ _
____ _____ "<<end
l;
cout<<" /\\ \\
/\\ \\ /\\ \\
/\\ \\ /\\ \\
"<<endl;
cout<<" /::\\ \\
/::\\ \\ /::\\ \\
/::\\ \\ /::\\ \\
"<<endl;
cout<<" /::::\\ \\
\\:::\\ \\ /::::\\ \\
\\:::\\ \\ \\:::\\ \\
"<<endl;
cout<<" /::::::\\ \\
\\:::\\ \\ /::::::\\ \\
\\:::\\ \\ \\:::\\ \\
"<<endl;
cout<<" /:::/\\:::\\ \
\ \\:::\\ \\ /:::/\\:::\\ \\
\\:::\\ \\ \\:::\\ \\
"<<endl;
cout<<" /:::/ \\:::\\
\\ \\:::\\ \\ /:::/ \\:::\\ \\
\\:::\\ \\ \\:::\\ \\
"<<endl;
cout<<" /:::/ \\:::\\
\\ /::::\\ \\ /:::/ \\:::\\ \\
/::::\\ \\ /::::\\ \\
"<<endl;
cout<<" /:::/ / \\:::\\
\\ ____ /::::::\\ \\ /:::/ / \\:::\\ \\ _
___ /::::::\\ \\ /::::::\\ \\
"<<endl;
cout<<" /:::/ / \\:::\\
___\\ /\\ \\ /:::/\\:::\\ \\ /:::/ / \\:::\\ ___\
\ /\\ \\ /:::/\\:::\\ \\ /:::/\\:::\\ \\
"<<endl;
cout<<" /:::/____/ \\:::|
/::\\ \\/:::/ \\:::\\____/:::/____/ ___\\:::| /::\\
\\/:::/ \\:::\\____\\/:::/ \\:::\\____\\
"<<endl;
cout<<" \\:::\\ \\ /:::
|____\\:::\\ /:::/ \\::/ \\:::\\ \\ /\\ /:::|
____\\:::\\ /:::/ \\::/ /:::/ \\::/ /
"<<endl;
cout<<" \\:::\\ \\ /:::/
/ \\:::\\/:::/ / \\/____/ \\:::\\ /::\\ \\::/ /
\\:::\\/:::/ / \\/____/:::/ / \\/____/
"<<endl;
cout<<" \\:::\\ \\ /:::/
/ \\::::::/ / \\:::\\ \\:::\\ \\/____/
\\::::::/ / /:::/ /
"<<endl;
cout<<" \\:::\\ /:::/
/ \\::::/____/ \\:::\\ \\:::\\____\\
\\::::/____/ /:::/ /
"<<endl;
cout<<" \\:::\\ /:::/
/ \\:::\\ \\ \\:::\\ /:::/ /
\\:::\\ \\ \\::/ /
"<<endl;
cout<<" \\:::\\/:::/ /
\\:::\\ \\ \\:::\\/:::/ /
\\:::\\ \\ \\/____/
"<<endl;
cout<<" \\::::::/ /
\\:::\\ \\ \\::::::/ /
\\:::\\ \\
"<<endl;
cout<<" \\::::/ /
\\:::\\____\\ \\::::/ /
\\:::\\____\\
"<<endl;
cout<<" \\::/____/
\\::/ / \\::/____/
\\::/ / "<
<endl;
cout<<" ~~
\\/____/ \
\/____/ "<<e
ndl;
}
int main()
{
map<string,long int> contact_list ;
int choice;
intro();
do
{
cout<<"enter 1 for showing the contact list"<<endl;
cout<<"enter 2 for searching the contact by entering the a
lbhabet"<<endl;
cout<<"enter 3 for searching the contact by digit"<<endl;
cout<<"enter 4 search the contact no. when the last two di
gits are missing"<<endl;
cout<<"enter 5 for exit"<<endl;
cout<<"enter the choice"<<endl;
cin>>choice;
switch(choice)
{
case 1:
{
contact_list.insert(pair<string,long int>{"Mahi",783925528
4});
contact_list.insert(pair<string,long int>{"Shivi",89392552
84});
contact_list.insert(pair<string,long int>{"Divya",96392552
84});
contact_list.insert(pair<string,long int>{"Aarav",56392552
84});
contact_list.insert(pair<string,long int>{"Lavika",9639255
284});
contact_list.insert(pair<string,long int>{"Lavina",8518510
185});
contact_list.insert(pair<string,long int>{"Lavisha",451098
7655});
contact_list.insert(pair<string,long int>{"Lavi",676789564
5});
contact_list.insert(pair<string,long int>{"Reyansh",603456
7891});
contact_list.insert(pair<string,long int>{"Dora",703456789
6});
contact_list.insert(pair<string,long int>{"Novita",8003456
789});
contact_list.insert(pair<string,long int>{"Naini",90834567
89});
contact_list.insert(pair<string,long int >{"Jasmine",56034
56789});
// contact_list.rehash();
// cout<<"***************************THE CONTACT LIST IS***
*****************************"<<endl;
contacts();
map<string, long int>::iterator itr;
cout<<"\t\t\t\t\t\t\t\t\t\
t====================================================="<<end
l;
for (itr = contact_list.begin(); itr != contact_list.end()
; ++itr) {
cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << itr->first << "\t"
<< itr->second<<endl;
}
cout<<"\t\t\t\t\t\t\t\t\t\
t====================================================="<<end
l;
//print_map(contact_list);
break;
}
case 2:
{
// cout<<"*****************************Searching by al
phabets*****************************"<<endl;
alpha();
int j;
char ans;
int flag=0;
string arr[] = {"Lavika", "Lavina", "Jasmine","Mahi","
shivi","Divya","Aarav",
"Lavisha", "Lavi","Naini","Doreamon","Reyansh","Nov
ita"};
int n = sizeof (arr) / sizeof (arr[0]);
//ans = commonPrefix(arr, n);
cout<<"ENTER THE ALPHABET FOR WHICH U WANT TO SEARCH T
HE CONTACT"<<endl;
cin>>ans;
ans=toupper(ans);
cout<<"\t\t\t\t\t\t\t\t\t\
t====================SUGGESTED CONTACTS ARE=================
==============="<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\
t===========================================================
================"<<endl;
for(j=0;j<n;j++){
if (ans==arr[j].at(0))
{
cout << "\t\t\t\t\t\t\t\t\t\t\t\t"<<arr[j]<<endl;
flag++;
}
}
cout<<"\t\t\t\t\t\t\t\t\t\
t===========================================================
============"<<endl;
if(flag==0)
{
cout << "There is no contact with this name"<<endl;
}
break;
}
//
============================================================
============================
case 3:
{
// cout<<"*******************************Searching by Dig
it*************************************"<<endl;
digits();
string names[] = {"Lavika", "Lavina", "Jasmine","Mahi","
Shivi","Divya","Aarav",
"Lavisha", "Lavi","Naini","Doreamon","Reyansh","Nov
ita"};
char in[100]="";
char out[100]="";
int flag=0;
cout<<"enter the digit to search the contact"<<endl;
cin>>in;
printbydigit(in,out);
//cout<<"suggested names are"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t====================SUGGESTED
NAMES ARE================================"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\
t===========================================================
================"<<endl;
for(int i=0;i<strlen(out);i++)
{
int size = sizeof(names)/sizeof(names[0]);
for(int j=0;j<size;j++)
{
if(out[i]==names[j].at(0))
{
cout<<"\t\t\t\t\t\t\t\t\t\t\t\tName is : "<<names[j
]<<endl;
flag++;
}
}
}
cout<<"\t\t\t\t\t\t\t\t\t\
t===========================================================
============"<<endl;
if(flag==0)
{
cout<<"names not found"<<endl;
}
break;
}
case 4:
{
long int n;
cout<<"enter the eight digit of phone no."<<endl;
cin>>n;
findPhoneNumber(n);
break;
}
case 5:
{
exit(0);
}
}
}while(choice!=0);
return 0;
}