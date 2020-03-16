/*
 * Copyright (C) 2017 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <WebKit/WKFoundation.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

WK_CLASS_AVAILABLE(macos(10.13), ios(11.0))
@interface _WKWebsiteDataStoreConfiguration : NSObject

- (instancetype)init; // Creates a persistent configuration.
- (instancetype)initNonPersistentConfiguration WK_API_AVAILABLE(macos(WK_MAC_TBA), ios(WK_IOS_TBA));

@property (nonatomic, readonly, getter=isPersistent) BOOL persistent WK_API_AVAILABLE(macos(WK_MAC_TBA), ios(WK_IOS_TBA));

// These properties apply to both persistent and non-persistent data stores.
@property (nonatomic, nullable, copy) NSString *sourceApplicationBundleIdentifier WK_API_AVAILABLE(macos(10.14.4), ios(12.2));
@property (nonatomic, nullable, copy) NSString *sourceApplicationSecondaryIdentifier WK_API_AVAILABLE(macos(10.14.4), ios(12.2));
@property (nonatomic, nullable, copy, setter=setHTTPProxy:) NSURL *httpProxy WK_API_AVAILABLE(macos(10.14.4), ios(12.2));
@property (nonatomic, nullable, copy, setter=setHTTPSProxy:) NSURL *httpsProxy WK_API_AVAILABLE(macos(10.14.4), ios(12.2));
@property (nonatomic) BOOL deviceManagementRestrictionsEnabled WK_API_AVAILABLE(macos(WK_MAC_TBA), ios(WK_IOS_TBA));

// These properties only make sense for persistent data stores, and will throw
// an exception if set for non-persistent stores.
@property (nonatomic, copy, setter=_setWebStorageDirectory:) NSURL *_webStorageDirectory;
@property (nonatomic, copy, setter=_setIndexedDBDatabaseDirectory:) NSURL *_indexedDBDatabaseDirectory;
@property (nonatomic, copy, setter=_setWebSQLDatabaseDirectory:) NSURL *_webSQLDatabaseDirectory;
@property (nonatomic, copy, setter=_setCookieStorageFile:) NSURL *_cookieStorageFile;
@property (nonatomic, copy, setter=_setResourceLoadStatisticsDirectory:) NSURL *_resourceLoadStatisticsDirectory WK_API_AVAILABLE(macos(10.13.4), ios(11.3));
@property (nonatomic, copy, setter=_setCacheStorageDirectory:) NSURL *_cacheStorageDirectory WK_API_AVAILABLE(macos(10.13.4), ios(11.3));
@property (nonatomic, copy, setter=_setServiceWorkerRegistrationDirectory:) NSURL *_serviceWorkerRegistrationDirectory WK_API_AVAILABLE(macos(10.13.4), ios(11.3));

// Testing only.
@property (nonatomic) BOOL allLoadsBlockedByDeviceManagementRestrictionsForTesting WK_API_AVAILABLE(macos(WK_MAC_TBA), ios(WK_IOS_TBA));

@end

NS_ASSUME_NONNULL_END