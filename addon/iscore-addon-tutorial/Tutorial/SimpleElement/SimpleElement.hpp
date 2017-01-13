#pragma once
#include <iscore/model/IdentifiedObject.hpp>

namespace Tutorial
{
/**
 * @brief The simplest kind of model object that one can create.
 */
class SimpleElement final :
    public IdentifiedObject<SimpleElement> // Gives us an id.
{
        Q_OBJECT

    public:
        SimpleElement(
            const Id<SimpleElement>& id, // The ids are tagged with the type of the object
            QObject* parent);

        // Deserialization
        template<typename Impl>
        SimpleElement(Impl& vis, QObject* parent) :
            IdentifiedObject{vis, parent}
        {
            vis.writeTo(*this);
        }

        ~SimpleElement();
};
}
