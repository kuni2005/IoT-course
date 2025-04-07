
#ifndef USABLERESOURCE_H
#define USABLE_RESOURCE_H
#include <string>
#include "Resource.h"
class UsableResource final : public Resource{
 private:
   int capacity;

 public:
   UsableResource(const std::string& name, int capacity);
   [[nodiscard]] bool isAvailableForUse() const override;
   void allocate() override;
   void release() override;
   void use() const override;
};

#endif //USABLERESOURCE_H
