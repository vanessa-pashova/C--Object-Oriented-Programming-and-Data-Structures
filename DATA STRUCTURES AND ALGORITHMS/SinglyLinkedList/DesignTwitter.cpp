#include <iostream>
#include <vector>
#include "../Structs_Ready/LinkedListNode.h"

struct User {
    std::size_t userId;
    std::vector<std::size_t> following;
    Node<int> *tweets;
    User *nextUser;

    User(std::size_t userId) : userId(userId), tweets(nullptr), nextUser(nullptr) {}
};

class Twitter {
private:
    User *users;

    User *findUser(std::size_t id) {
        User *current = users;

        while(current) {
            if(current->userId == id)
                return current;

            current = current->nextUser;
        }

        return nullptr;
    }

    void addUser(std::size_t id) {
        if(!users) {
            users = new User(id);
            return;
        }

        else {
            User *current = users;
            while(current->nextUser)
                current = current->nextUser;

            current->nextUser = new User(id);
        }
    }

public:
    Twitter() : users(nullptr) {}

    void postTweet(std::size_t userId, int tweetId);
    void follow(std::size_t followerId, std::size_t userId);
    void unfollow(std::size_t followerId, std::size_t userId);
    void getNewsFeed(int userId);
};

void Twitter::postTweet(std::size_t userId, int tweetId) {
    User *user = findUser(userId);

    if(!user) {
        addUser(userId);
        user = findUser(userId);
    }

    Node<int> *newTweet = new Node<int>(tweetId);

    newTweet->next = user->tweets;
    user->tweets = newTweet;
}

void Twitter::follow(std::size_t followerId, std::size_t userId) {
    User *follower = findUser(followerId),
            *followee = findUser(userId);

    if(!follower || !followee)
        throw std::invalid_argument("User does not exist.");

    follower->following.push_back(userId);
}

void Twitter::unfollow(std::size_t followerId, std::size_t userId) {
    User *follower = findUser(followerId),
            *followee = findUser(userId);

    if(!follower || !followee)
        throw std::invalid_argument("User does not exist.");

    for(std::size_t i = 0; i < follower->following.size(); i++) {
        if(follower->following[i] == userId) {
            follower->following.erase(follower->following.begin() + i);
            break;
        }
    }
}

void Twitter::getNewsFeed(int userId) {
    User *user = findUser(userId);

    if(!user)
        throw std::invalid_argument("User does not exist.");

    std::vector<int> feed;
    Node<int> *temp = user->tweets;
    while (temp && feed.size() < 10) {
        feed.push_back(temp->data);
        temp = temp->next;
    }

    for (std::size_t followeeId : user->following) {
        User* followee = findUser(followeeId);

        if (!followee)
            continue;

        Node<int> *tempFollowee = followee->tweets;
        while (tempFollowee && feed.size() < 10) {
            feed.push_back(tempFollowee->data);
            tempFollowee = tempFollowee->next;
        }
    }

    std::cout << "News Feed for User " << userId << ": ";
    for (int id : feed)
        std::cout << id << " ";

    std::cout << "\n";
}

int main() {
    Twitter twitter;

    twitter.postTweet(1, 5);
    twitter.postTweet(1, 3);
    twitter.postTweet(2, 6);

    twitter.follow(1, 2);
    twitter.getNewsFeed(1);

    twitter.unfollow(1, 2);
    twitter.getNewsFeed(1);
}