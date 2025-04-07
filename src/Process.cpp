#include"Process.h"
#include <iostream>

Process::Process(
    const std::string &name,
    const std::string &description,
    const std::vector<std::string> &requiredResourcesNames,
    int durationInUnits)
        :Executable(name, description, requiredResourcesNames, durationInUnits)
    {}

void Process:: addResource(std::unique_ptr<Resource> resource) {
    resourcePool.push_back(std::move(resource));
}

void Process:: addTask(std::unique_ptr<Executable> task) {
    tasks.push_back(std::move(task));
}

void Process::execute() const {
    if (!requiredResourcesNames.empty() &&
        assignedResources.size() != requiredResourcesNames.size())
        throw std::runtime_error("Requires resource count does not match assigned resources count for " + name);
    std::cout<<"Executing process: " << name << std::endl;
    if (!assignedResources.empty())
        for (const auto& resource : assignedResources)
            resource->use();
    for (const auto& task : tasks) {
        try {
            if (task->canExecute(resourcePool)) {
                task->assignResource(resourcePool);
                std::cout<<"Executing task: " << task->getName() << std::endl;
                task->execute();
                task->releaseResources();
            } else {
                std::cout<<"Executing task: " << task->getName() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error executing task: " << task->getName() << ": " << e.what() << std::endl;
        }
    }
}

void Process::run() {
    try {
        if (requiredResourcesNames.empty() || canExecute(resourcePool)) {
            assignResource(resourcePool);
            execute();
            releaseResources();
            std::cout<<"Executing process: " << name << std::endl;
        } else {
            throw std::runtime_error("Insufficient resources to execute process: " + name);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error executing process: " << name << ": " << e.what() << std::endl;
    }
}
