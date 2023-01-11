class Vehicule
{
public:
    virtual void model() const;
    void nserie() const;
};

class Automobile: Vehicule
{
public:
    virtual void model() const;
    void nserie() const;
private:
    int x;
};

class Cabriolet: Automobile
{
public:
    void nserie() const;
private:
    int y;
};

int main(){

    Cabriolet x;
    return 0;
}