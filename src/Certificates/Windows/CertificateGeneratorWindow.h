//
// Created by Kasper de bruin on 27/03/2024.
//

#ifndef CAMELSNAKEUTIL_CERTIFICATEGENERATORWINDOW_H
#define CAMELSNAKEUTIL_CERTIFICATEGENERATORWINDOW_H

#include "../../Authenticator/touch_id_auth.h"

namespace HB::Utils::Certificates {
    class CertificateGeneratorWindow {
    public:
        CertificateGeneratorWindow();
        ~CertificateGeneratorWindow();

        void show();

    private:
        void createWindow();

        TouchIDAuthenticator* auth = new TouchIDAuthenticator();
        struct command {
            std::string name;
            std::string description;
            std::string command;

            bool runElevated = false;
        };

        std::vector<command> commands = {
                // {"Create directories",      "Create the directories for the certificates",     "rm -rf /opt/test/", false},
                {"Create directories",      "Create the directories for the certificates",     "mkdir /opt/test/", false},
                {"Create directories",      "Create the directories for the certificates",     "mkdir /opt/test/1", false},
                {"Create directories",      "Create the directories for the certificates",     "mkdir /opt/test/2", false},
                {"Create directories",      "Create the directories for the certificates",     "mkdir /opt/test/3", false},
//            {"Create directories",      "Create the directories for the certificates",     "sudo mkdir -p ./brk.local/{certs,crl,newcerts,private}", true},
//            {"Create directories",      "Create the directories for the certificates",     "sudo mkdir -p ./brk.local/{certs,crl,newcerts,private}", true},
//            {"Change permissions",      "Change the permissions of the private directory", "sudo chmod 700 ./brk.local/private", true},
//            {"Create index file",       "Create the index file",                           "sudo touch ./brk.local/index.txt", true},
//            {"Create serial file",      "Create the serial file",                          "sudo echo 1000 > ./brk.local/serial", true},
//            {"Generate CA key",         "Generate the CA key",                             "sudo openssl genrsa -aes256 -out ./brk.local/private/cakey.pem 4096", true},
//            {"Change permissions",      "Change the permissions of the CA key",            "sudo chmod 400 ./brk.local/private/cakey.pem", true},
//            {"Generate CA certificate", "Generate the CA certificate",                     "sudo openssl req -config openssl.conf -key ./brk.local/private/cakey.pem -new -x509 -days 7300 -sha256 -extensions v3_ca -out ./brk.local/cacert.pem, true"}
        };
    };
}


#endif //CAMELSNAKEUTIL_CERTIFICATEGENERATORWINDOW_H
