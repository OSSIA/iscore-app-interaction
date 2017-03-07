#include <ossia-max/src/logger.hpp>
#include <ossia/network/common/websocket_log_sink.hpp>

extern "C"
void* ossia_logger_new(t_symbol *s, long argc, t_atom *argv)
{
  using namespace ossia::max;
  auto& inst = singleton::instance();
  logger* x = (logger *) object_alloc(inst.ossia_logger_class);

  if (x)
  {
    new (&x->log) std::shared_ptr<spdlog::logger>();
    for (int i = 0; i < argc; i++)
    {
      if((argv + i)->a_type == A_SYM)
      {
        std::string ip = atom_getsym(argv+i)->s_name;
        x->log = std::make_shared<spdlog::logger>(
              "max_logger",
              std::make_shared<ossia::websocket_log_sink>(inst.get_connection(ip)));
        break;
      }
    }
  }

  return x;
}

extern "C"
void ossia_logger_in_anything(ossia::max::logger* x,
                              t_symbol *s, long argc, t_atom *argv)
{
  if(x && x->log)
    x->log->info("{}", s->s_name);
}

extern "C"
void ossia_logger_free(ossia::max::logger* x)
{
  if(x)
  {
    x->log.reset();
    x->log.~shared_ptr();
    ossia::max::singleton::instance().collect_garbage();
  }
}
