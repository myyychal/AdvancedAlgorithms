class Node {

protected:
    char symbol;
    int count;
public:
    char getSymbol() const;

    void setSymbol(char symbol);

    int getCount() const;

    void setCount(int count);

    Node();

    Node(char s,int c);
};