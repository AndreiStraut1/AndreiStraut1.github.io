#include <iostream>
#include<list>
using namespace std;

class YouTubeChannel{
private:
    string Name;
    int SubscribersCount;
    list<string> PublishedVideoTitles;
protected:
    string OwnerName;
    int ContentQuality;
public:
    YouTubeChannel(string name, string ownerName){
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        ContentQuality = 0;
    }

    void GetInfo()
    {
        cout<<"Name: "<<Name<<"\n"<<"Owner Name: "<<OwnerName<<"\n"
                    <<"Subscribers count: "<<SubscribersCount<<"\n";

        cout<<"Videos: "<<endl;

        for(string videoTitle : PublishedVideoTitles)
        {
            cout<< videoTitle << endl;
        }
    }
    void Subscribe()
    {
        SubscribersCount++;
    }
    void Unsubscribe()
    {
        if(SubscribersCount > 0)
            SubscribersCount--;
    }

    void PublishVideo(string title)
    {
        PublishedVideoTitles.push_back(title);
    }

    void CheckAnalytics()
    {
        if(ContentQuality < 5)
            cout << Name << " has bad quality content."<<endl;
        else
            cout << Name << " has good content."<<endl;
    }

};

class CookingYoutubeChannel:public YouTubeChannel
{
public:
    CookingYoutubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName)
    {

    }
    void Practice()
    {
        cout<<OwnerName<<" practices cookie, learning coochie, experimenting with races..."<<endl;
        ContentQuality++;
    }
};

class SingersYoutubeChannel:public YouTubeChannel
{
public:
    SingersYoutubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName)
    {

    }
    void Practice()
    {
        cout<<OwnerName<<" sing dance chestii"<<endl;
        ContentQuality++;

    }
};

int main()
{
    CookingYoutubeChannel cookingYtChannel("Gogo chicken", "Gigel");
//    cookingYtChannel.PublishVideo("cum sa faci ciorba de mieipula");
//    cookingYtChannel.PublishVideo("imi place sa mananc");
//    cookingYtChannel.Subscribe();
//    cookingYtChannel.Subscribe();
//
//    cookingYtChannel.GetInfo();
//    cookingYtChannel.Practice();

    YouTubeChannel ytChannel("cockBeauty", "Johnny sins");

    SingersYoutubeChannel singersYtChannel("Gogosings", "boos");
    cookingYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();

    YouTubeChannel* yt1 = &cookingYtChannel;
    YouTubeChannel* yt2 = &singersYtChannel;

    yt1->CheckAnalytics();
    yt2->CheckAnalytics();

    cookingYtChannel.CheckAnalytics();
}
