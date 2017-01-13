#pragma once
#include <iscore/model/Entity.hpp>

namespace Tutorial
{
class SimpleEntity final :
        public iscore::Entity<SimpleEntity>
{
        Q_OBJECT

    public:
        SimpleEntity(const Id<SimpleEntity>& id, QObject* parent);

        ~SimpleEntity();
};
}
