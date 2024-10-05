#include <iostream>
#include <string>
#include <list>
using namespace std;

class YouTubeChannel
{
private:
    string Name;
    int SubscribersCount;

public:
    friend ostream& operator<<(ostream&, YouTubeChannel&);
    YouTubeChannel(string name, int subscribersCount)
    {
        Name = name;
        SubscribersCount = subscribersCount;
    }
    bool operator==(const YouTubeChannel& channel) const
    {
        return this->Name == channel.Name;
    }

};
ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel)
{
    COUT<<"Name: "<<ytChannel.Name<<endl;
    COUT<<"Subscribers: "<<ytChannel.SubscribersCount<<endl;
    return COUT;
}

class MyCollection
{
private:
    list<YouTubeChannel>myChannels;


public:
    friend ostream& operator<<(ostream&, MyCollection&);
    void operator+=(YouTubeChannel& channel)
    {
        this->myChannels.push_back(channel);
    }
    void operator-=(YouTubeChannel& channel)
    {
        this->myChannels.remove(channel);
    }

};

ostream& operator<<(ostream& COUT, MyCollection& myCollection)
{
    for(YouTubeChannel ytChannel : myCollection.myChannels)
        COUT << ytChannel << endl;
    return COUT;
}

int main()
{
    YouTubeChannel yt1 = YouTubeChannel("Gogoshar", 69);
    YouTubeChannel yt2 = YouTubeChannel("Gogoshar2", 54);
    cout << yt1 << yt2<<endl;
    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2;

    cout << myCollection;

    return 0;
}
