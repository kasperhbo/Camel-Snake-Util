#include "touch_id_auth.h"
#import <LocalAuthentication/LocalAuthentication.h>
#include <iostream>

void TouchIDAuthenticator::executeCommandWithElevation(const std::string &command) {
    if (authRef == nullptr) {
        initializeAuthorization();
    }
    if (authRef == nullptr) {
        NSLog(@"Authorization reference is not initialized");
        return;
    }

    FILE *pipe = nullptr;
    // Prepare for executing the command
    char *args[] = { (char *)"-c", (char *)command.c_str(), NULL };


    OSStatus status = AuthorizationExecuteWithPrivileges(authRef, "/bin/sh", kAuthorizationFlagDefaults, args, &pipe);
    if (status != errAuthorizationSuccess) {
        std::cerr << "Execution error: " << status << std::endl;
    }

}

void TouchIDAuthenticator::initializeAuthorization() {
    {
        if (authRef == nullptr) {

            OSStatus status = AuthorizationCreate(NULL, kAuthorizationEmptyEnvironment, kAuthorizationFlagDefaults,
                                                  &authRef);
            if (status != errAuthorizationSuccess) {
                NSLog(@"Failed to create AuthorizationRef");
            }else{
                NSLog(@"Created AuthorizationRef");
            }
        }
    }
}

TouchIDAuthenticator::~TouchIDAuthenticator() {
    {
        if (authRef != nullptr) {
            AuthorizationFree(authRef, kAuthorizationFlagDefaults);
        }
    }

}
