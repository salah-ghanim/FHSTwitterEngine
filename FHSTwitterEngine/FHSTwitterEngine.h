//
//  FHSTwitterEngine.h
//  FHSTwitterEngine
//
//  Created by Nathaniel Symer on 8/22/12.
//  Copyright (C) 2012 Nathaniel Symer.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

//
// FHSTwitterEngine
// The synchronous Twitter engine that doesn’t suck!!
//

#import <Foundation/Foundation.h>
#import "FHSOAuthModel.h"
#import "FHSDefines.h"

#import "NSError+FHSTE.h"
#import "NSData+FHSTE.h"
#import "NSString+FHSTE.h"
#import "NSObject+FHSTE.h"
#import "NSURL+FHSTE.h"

@interface FHSTwitterEngine : NSObject

//
// REST API
//

#pragma mark - Statuses/update

/**
 Post a tweet.
 @param tweetString Tweet to post
 */
- (NSError *)postTweet:(NSString *)tweetString;

/**
 Post a reply to a tweet.
 @param tweetString Reply
 @param inReplyToString tweet ID to reply to
 */
- (NSError *)postTweet:(NSString *)tweetString inReplyTo:(NSString *)inReplyToString;


#pragma mark - Statuses/home_timeline

/**
 Get timeline of tweets for authenticated user.
 @param sinceID Timeline will return tweets with ID greater than this value (optional)
 @param count Number of tweets to retrieve
 @return Timeline of tweets
 */

- (id)getHomeTimelineSinceID:(NSString *)sinceID count:(int)count;

// help/test
- (id)testService;

// blocks/create
- (NSError *)block:(NSString *)username;

// blocks/destroy
- (NSError *)unblock:(NSString *)username;

// users/lookup
- (id)lookupUsers:(NSArray *)users areIDs:(BOOL)areIDs;

// users/search
- (id)searchUsersWithQuery:(NSString *)q andCount:(int)count;

// account/update_profile_image
- (NSError *)setProfileImageWithImageAtPath:(NSString *)file;
- (NSError *)setProfileImageWithImageData:(NSData *)data;

// account/settings GET and POST
// See FHSTwitterEngine.m For details
- (id)getUserSettings;
- (NSError *)updateSettingsWithDictionary:(NSDictionary *)settings;

// account/update_profile
// See FHSTwitterEngine.m for details
- (NSError *)updateUserProfileWithDictionary:(NSDictionary *)settings;

// account/update_profile_background_image
- (NSError *)setProfileBackgroundImageWithImageData:(NSData *)data tiled:(BOOL)isTiled;
- (NSError *)setProfileBackgroundImageWithImageAtPath:(NSString *)file tiled:(BOOL)isTiled;
- (NSError *)setUseProfileBackgroundImage:(BOOL)shouldUseProfileBackgroundImage;

// account/update_profile_colors
// See FHSTwitterEngine.m for details
// If the dictionary is nil, FHSTwitterEngine resets the values
- (NSError *)updateProfileColorsWithDictionary:(NSDictionary *)dictionary;

// application/rate_limit_status
- (id)getRateLimitStatus;

// favorites/create, favorites/destroy
- (NSError *)markTweet:(NSString *)tweetID asFavorite:(BOOL)flag;

// favorites/list
- (id)getFavoritesForUser:(NSString *)user isID:(BOOL)isID andCount:(int)count;
- (id)getFavoritesForUser:(NSString *)user isID:(BOOL)isID andCount:(int)count sinceID:(NSString *)sinceID maxID:(NSString *)maxID;

// account/verify_credentials
- (id)verifyCredentials;

// friendships/create
- (NSError *)followUser:(NSString *)user isID:(BOOL)isID;

// friendships/destroy
- (NSError *)unfollowUser:(NSString *)user isID:(BOOL)isID;

// friendships/lookup
- (id)lookupFriendshipStatusForUsers:(NSArray *)users areIDs:(BOOL)areIDs;

// friendships/incoming
- (id)getPendingIncomingFollowers;

// friendships/outgoing
- (id)getPendingOutgoingFollowers;

// friendships/update
- (NSError *)enableRetweets:(BOOL)enableRTs andDeviceNotifs:(BOOL)devNotifs forUser:(NSString *)user isID:(BOOL)isID;

// friendships/no_retweet_ids
- (id)getNoRetweetIDs;

// help/tos
- (id)getTermsOfService;

// help/privacy
- (id)getPrivacyPolicy;

// direct_messages
- (id)getDirectMessages:(int)count;

// direct_messages/destroy
- (NSError *)deleteDirectMessage:(NSString *)messageID;

// direct_messages/sent
- (id)getSentDirectMessages:(int)count;

// direct_messages/new
- (NSError *)sendDirectMessage:(NSString *)body toUser:(NSString *)user isID:(BOOL)isID;

// direct_messages/show
- (id)showDirectMessage:(NSString *)messageID;

// users/report_spam
- (NSError *)reportUserAsSpam:(NSString *)user isID:(BOOL)isID;

// help/configuration
- (id)getConfiguration;

// help/languages
- (id)getLanguages;

// blocks/blocking/ids
- (id)listBlockedIDs;

// blocks/blocking
- (id)listBlockedUsers;

// blocks/exists
- (id)authenticatedUserIsBlocking:(NSString *)user isID:(BOOL)isID;

// users/profile_image
- (id)getProfileImageForUsername:(NSString *)username andSize:(FHSTwitterEngineImageSize)size;
- (id)getProfileImageURLStringForUsername:(NSString *)username andSize:(FHSTwitterEngineImageSize)size;

// statuses/user_timeline
- (id)getTimelineForUser:(NSString *)user isID:(BOOL)isID count:(int)count;
- (id)getTimelineForUser:(NSString *)user isID:(BOOL)isID count:(int)count sinceID:(NSString *)sinceID maxID:(NSString *)maxID;

// statuses/retweet
- (NSError *)retweet:(NSString *)identifier;

// statuses/show
- (id)getDetailsForTweet:(NSString *)identifier;

// statuses/destroy
- (NSError *)destroyTweet:(NSString *)identifier;

// statuses/update_with_media
- (NSError *)postTweet:(NSString *)tweetString withImageData:(NSData *)theData;
- (NSError *)postTweet:(NSString *)tweetString withImageData:(NSData *)theData inReplyTo:(NSString *)irt;

// statuses/mentions_timeline
- (id)getMentionsTimelineWithCount:(int)count;
- (id)getMentionsTimelineWithCount:(int)count sinceID:(NSString *)sinceID maxID:(NSString *)maxID;

// statuses/retweets_of_me
- (id)getRetweetedTimelineWithCount:(int)count;
- (id)getRetweetedTimelineWithCount:(int)count sinceID:(NSString *)sinceID maxID:(NSString *)maxID;

// statuses/retweets
- (id)getRetweetsForTweet:(NSString *)identifier count:(int)count;

// lists/list
- (id)getListsForUser:(NSString *)user isID:(BOOL)isID;

// lists/statuses
- (id)getTimelineForListWithID:(NSString *)listID count:(int)count;
- (id)getTimelineForListWithID:(NSString *)listID count:(int)count sinceID:(NSString *)sinceID maxID:(NSString *)maxID;
- (id)getTimelineForListWithID:(NSString *)listID count:(int)count excludeRetweets:(BOOL)excludeRetweets excludeReplies:(BOOL)excludeReplies;
- (id)getTimelineForListWithID:(NSString *)listID count:(int)count sinceID:(NSString *)sinceID maxID:(NSString *)maxID excludeRetweets:(BOOL)excludeRetweets excludeReplies:(BOOL)excludeReplies;

// lists/members/create_all
- (NSError *)addUsersToListWithID:(NSString *)listID users:(NSArray *)users;

// lists/members/destroy_all
- (NSError *)removeUsersFromListWithID:(NSString *)listID users:(NSArray *)users;

// lists/members
- (id)listUsersInListWithID:(NSString *)listID;

// lists/update
- (NSError *)updateListWithID:(NSString *)listID name:(NSString *)name;
- (NSError *)updateListWithID:(NSString *)listID description:(NSString *)description;
- (NSError *)updateListWithID:(NSString *)listID mode:(BOOL)isPrivate;
- (NSError *)updateListWithID:(NSString *)listID name:(NSString *)name description:(NSString *)description mode:(BOOL)isPrivate;

// lists/show
- (id)getListWithID:(NSString *)listID;

// lists/create
- (NSError *)createListWithName:(NSString *)name isPrivate:(BOOL)isPrivate description:(NSString *)description;

// tweets/search
- (id)searchTweetsWithQuery:(NSString *)q count:(int)count resultType:(FHSTwitterEngineResultType)resultType unil:(NSDate *)untilDate sinceID:(NSString *)sinceID maxID:(NSString *)maxID;

// followers/ids
- (id)getFollowersIDs;

// followers/list
- (id)listFollowersForUser:(NSString *)user isID:(BOOL)isID withCursor:(NSString *)cursor;

// friends/ids
- (id)getFriendsIDs;

// friends/list
- (id)listFriendsForUser:(NSString *)user isID:(BOOL)isID withCursor:(NSString *)cursor;

// TwitPic
- (id)uploadImageToTwitPic:(UIImage *)image withMessage:(NSString *)message twitPicAPIKey:(NSString *)twitPicAPIKey;
- (id)uploadImageDataToTwitPic:(NSData *)imageData withMessage:(NSString *)message twitPicAPIKey:(NSString *)twitPicAPIKey;

//
// Streaming
//

- (void)streamUserMessagesWith:(NSArray *)with replies:(BOOL)replies keywords:(NSArray *)keywords locationBox:(NSArray *)locBox block:(StreamBlock)block;
- (void)streamPublicStatusesForUsers:(NSArray *)users keywords:(NSArray *)keywords locationBox:(NSArray *)locBox block:(StreamBlock)block;
- (void)streamSampleStatusesWithBlock:(StreamBlock)block;
- (void)streamFirehoseWithBlock:(StreamBlock)block;

//
// Login and Auth
//

// OAuth
- (id)getRequestToken;
- (BOOL)finishAuthWithRequestToken:(FHSToken *)reqToken;

// xAuth
- (NSError *)authenticateWithUsername:(NSString *)username password:(NSString *)password;

// Access Token Mangement
- (void)clearAccessToken;
- (void)loadAccessToken;
- (BOOL)isAuthorized;

// API Key management
- (void)clearConsumer;
- (void)temporarilySetConsumerKey:(NSString *)consumerKey andSecret:(NSString *)consumerSecret; // key pair is used for one request
- (void)permanentlySetConsumerKey:(NSString *)consumerKey andSecret:(NSString *)consumerSecret; // key pair is used indefinitely

// id/username concatenator - returns an array of concatenated id/username lists
// 100 ids/usernames per concatenated string
- (NSArray *)generateRequestStringsFromArray:(NSArray *)array;

// never call -[FHSTwitterEngine init] directly.
+ (FHSTwitterEngine *)sharedEngine;

// Singleton for a date formatter that
// Is configured to parse Twitter's dates
+ (NSDateFormatter *)dateFormatter;

+ (BOOL)isConnectedToInternet;

@property (assign, nonatomic) BOOL shouldClearConsumer;

@property (nonatomic, assign) BOOL includeEntities;
@property (nonatomic, strong) FHSToken *accessToken;
@property (strong, nonatomic) FHSConsumer *consumer;
//@property (nonatomic, strong) NSDateFormatter *dateFormatter;

// Blocks to load the access token or store the access token
@property (nonatomic, copy) StoreAccessTokenBlock storeAccessTokenBlock;
@property (nonatomic, copy) LoadAccessTokenBlock loadAccessTokenBlock;

@end
