//
// Created by Kasper de bruin on 21/03/2024.
//

#ifndef CAMELSNAKEUTIL_GITLABMANAGER_H
#define CAMELSNAKEUTIL_GITLABMANAGER_H

#include <iostream>
#include <unordered_map>

namespace HB::Utils::Gitlab {

    class GitlabManager {
    private:
        struct GitlabProject {
            std::string id;
            std::string name;
            std::string description;

            std::string url;
            std::string sshUrl;
        };

        struct GitlabGroup {
            std::string id;
            std::string name;
            std::string description;

            std::string url;

            std::unordered_map<std::string, GitlabProject> projects;
        };

    public:
        explicit GitlabManager(std::string token);

        ~GitlabManager();

    private:
        [[maybe_unused]] void fetchGroups();

        [[maybe_unused]] void fetchProjectsForGroup(const std::string &groupId);

    private:
        std::string token;
        std::unordered_map<std::string, GitlabGroup> groups = {};

        const std::string c_Url = "https://gitlab.com/api/v4/";
        const std::string c_GroupsUrl = c_Url + "groups";
        const std::string c_ProjectsUrl = c_Url + "projects";
    };

} // Gitlab
#endif //CAMELSNAKEUTIL_GITLABMANAGER_H
