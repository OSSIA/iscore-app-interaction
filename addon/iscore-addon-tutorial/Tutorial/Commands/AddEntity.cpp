#include "AddEntity.hpp"
#include <iscore/model/path/PathSerialization.hpp>
#include <iscore/application/ApplicationContext.hpp>
#include <iscore/tools/IdentifierGeneration.hpp>
#include <ossia/detail/logger.hpp>

namespace Tutorial
{
AddEntity::AddEntity(
        const Tutorial::ProcessModel& model,
    PolymorphicElementFactory::ConcreteKey key):
    m_model{model},
    m_key{key},
    m_id{getStrongId(model.polymorphicEntities)}
{
  // Notice how we generate the identifier in the constructor.
  // This is because if later commands refer to the object
  // that will be created, we have to ensure that the object's
  // id will be fixed (i.e. won't change every time we do undo - redo),
  // so that we can find it again.
}

void AddEntity::undo() const
{
    Tutorial::ProcessModel& proc = m_model.find();

    // Here we just have to remove what we have created
    proc.polymorphicEntities.remove(m_id);
}

void AddEntity::redo() const
{
    //! Find the object
    Tutorial::ProcessModel& proc = m_model.find();

    //! Find the factory
    auto factory = context
                    .interfaces<PolymorphicElementFactoryList>()
                    .get(m_key);
    if(factory)
    {
      // The container
      proc.polymorphicEntities
          .add( // Add to it
            factory->make( // A new factory
              m_id, // With the generated id
              &proc // The parent is the process
              )
            );
    }
    else
    {
      //! An error should certainly be thrown here.
      ossia::logger().error("Entity could not be created");
    }
}

void AddEntity::serializeImpl(DataStreamInput& s) const
{
    // Don't forget to serialize everything.
    s << m_model << m_key << m_id;
}

void AddEntity::deserializeImpl(DataStreamOutput& s)
{
    // Don't forget to deserialize everything.
    s >> m_model >> m_key >> m_id;
}
}
