TEMPLATE = app

QT += qml quick widgets quickcontrols2
CONFIG += c++11

SOURCES += \
    main.cpp \
    Signal.cpp \
    extract.cpp \
    OSSIA/ossia/detail/instantiations.cpp \
    OSSIA/ossia/editor/automation/automation.cpp \
    OSSIA/ossia/editor/curve/curve.cpp \
    OSSIA/ossia/editor/dataspace/detail/dataspace_impl.cpp \
    OSSIA/ossia/editor/dataspace/dataspace.cpp \
    OSSIA/ossia/editor/dataspace/dataspace_visitors.cpp \
    OSSIA/ossia/editor/expression/expression.cpp \
    OSSIA/ossia/editor/expression/expression_atom.cpp \
    OSSIA/ossia/editor/expression/expression_bool.cpp \
    OSSIA/ossia/editor/expression/expression_composition.cpp \
    OSSIA/ossia/editor/expression/expression_generic.cpp \
    OSSIA/ossia/editor/expression/expression_not.cpp \
    OSSIA/ossia/editor/expression/expression_pulse.cpp \
    OSSIA/ossia/editor/loop/loop.cpp \
    OSSIA/ossia/editor/mapper/mapper.cpp \
    OSSIA/ossia/editor/scenario/clock.cpp \
    OSSIA/ossia/editor/scenario/scenario.cpp \
    OSSIA/ossia/editor/scenario/time_constraint.cpp \
    OSSIA/ossia/editor/scenario/time_event.cpp \
    OSSIA/ossia/editor/scenario/time_node.cpp \
    OSSIA/ossia/editor/scenario/time_process.cpp \
    OSSIA/ossia/editor/state/message.cpp \
    OSSIA/ossia/editor/state/state.cpp \
    OSSIA/ossia/editor/state/state_element.cpp \
    OSSIA/ossia/editor/value/value.cpp \
    OSSIA/ossia/network/base/address.cpp \
    OSSIA/ossia/network/base/device.cpp \
    OSSIA/ossia/network/base/node.cpp \
    OSSIA/ossia/network/base/protocol.cpp \
    OSSIA/ossia/network/common/complex_type.cpp \
    OSSIA/ossia/network/common/debug.cpp \
    OSSIA/ossia/network/common/extended_types.cpp \
    OSSIA/ossia/network/common/path.cpp \
    OSSIA/ossia/network/domain/detail/domain_impl.cpp \
    OSSIA/ossia/network/domain/clamp.cpp \
    OSSIA/ossia/network/domain/clamp_max.cpp \
    OSSIA/ossia/network/domain/clamp_min.cpp \
    OSSIA/ossia/network/domain/domain_base.cpp \
    OSSIA/ossia/network/domain/fold.cpp \
    OSSIA/ossia/network/domain/wrap.cpp \
    OSSIA/ossia/network/generic/alias_node.cpp \
    OSSIA/ossia/network/generic/generic_address.cpp \
    OSSIA/ossia/network/generic/generic_device.cpp \
    OSSIA/ossia/network/generic/generic_node.cpp \
    OSSIA/ossia/network/local/local.cpp \
    OSSIA/ossia/network/midi/midi_address.cpp \
    OSSIA/ossia/network/midi/midi_device.cpp \
    OSSIA/ossia/network/midi/midi_node.cpp \
    OSSIA/ossia/network/midi/midi_protocol.cpp \
    OSSIA/ossia/network/minuit/detail/minuit_impl.cpp \
    OSSIA/ossia/network/minuit/minuit.cpp \
    OSSIA/ossia/network/osc/osc.cpp \
    OSSIA/ossia/network/oscquery/detail/attributes.cpp \
    OSSIA/ossia/network/oscquery/detail/json_reader_detail.cpp \
    OSSIA/ossia/network/oscquery/detail/json_writer_detail.cpp \
    OSSIA/ossia/network/oscquery/detail/query_parser.cpp \
    OSSIA/ossia/network/oscquery/detail/typetag.cpp \
    OSSIA/ossia/network/oscquery/oscquery_mirror.cpp \
    OSSIA/ossia/network/oscquery/oscquery_server.cpp \
    OSSIA/ossia/network/zeroconf/zeroconf.cpp \
    OSSIA/ossia/context.cpp \
    OSSIA/ossia/ossia.cpp \
    OSSIA/ossia-qt/device/qml_device.cpp \
    OSSIA/ossia-qt/device/qml_node.cpp \
    OSSIA/ossia-qt/device/qml_node_base.cpp \
    OSSIA/ossia-qt/device/qml_property.cpp \
    OSSIA/ossia-qt/device/qt_device.cpp \
    OSSIA/ossia-qt/device/qt_object_node.cpp \
    OSSIA/ossia-qt/device/qt_property_node.cpp \
    OSSIA/ossia-qt/http/http_address.cpp \
    OSSIA/ossia-qt/http/http_device.cpp \
    OSSIA/ossia-qt/http/http_node.cpp \
    OSSIA/ossia-qt/http/http_protocol.cpp \
    OSSIA/ossia-qt/serial/serial_address.cpp \
    OSSIA/ossia-qt/serial/serial_device.cpp \
    OSSIA/ossia-qt/serial/serial_node.cpp \
    OSSIA/ossia-qt/serial/serial_protocol.cpp \
    OSSIA/ossia-qt/websocket-generic-client/ws_generic_client_address.cpp \
    OSSIA/ossia-qt/websocket-generic-client/ws_generic_client_device.cpp \
    OSSIA/ossia-qt/websocket-generic-client/ws_generic_client_node.cpp \
    OSSIA/ossia-qt/websocket-generic-client/ws_generic_client_protocol.cpp \
    OSSIA/ossia-qt/js_utilities.cpp \
    OSSIA/ossia-qt/qml_plugin.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -lGL

DISTFILES += \
    ../interactions.json \
    OSSIA/ossia-qt/qml/qmldir \
    OSSIA/ossia-qt/qml/OssiaProperty.qml

HEADERS += \
    Signal.hpp \
    extract.hpp \
    OSSIA/ossia/detail/algorithms.hpp \
    OSSIA/ossia/detail/any_map.hpp \
    OSSIA/ossia/detail/callback_container.hpp \
    OSSIA/ossia/detail/config.hpp \
    OSSIA/ossia/detail/destination_index.hpp \
    OSSIA/ossia/detail/instantiations.hpp \
    OSSIA/ossia/detail/json.hpp \
    OSSIA/ossia/detail/locked_container.hpp \
    OSSIA/ossia/detail/logger.hpp \
    OSSIA/ossia/detail/math.hpp \
    OSSIA/ossia/detail/mutex.hpp \
    OSSIA/ossia/detail/optional.hpp \
    OSSIA/ossia/detail/ptr_container.hpp \
    OSSIA/ossia/detail/string_map.hpp \
    OSSIA/ossia/detail/string_view.hpp \
    OSSIA/ossia/editor/automation/automation.hpp \
    OSSIA/ossia/editor/automation/curve_value_visitor.hpp \
    OSSIA/ossia/editor/curve/curve_segment/easing.hpp \
    OSSIA/ossia/editor/curve/curve_segment/empty.hpp \
    OSSIA/ossia/editor/curve/curve_segment/linear.hpp \
    OSSIA/ossia/editor/curve/curve_segment/power.hpp \
    OSSIA/ossia/editor/curve/curve_segment/sin.hpp \
    OSSIA/ossia/editor/curve/behavior.hpp \
    OSSIA/ossia/editor/curve/curve.hpp \
    OSSIA/ossia/editor/curve/curve_abstract.hpp \
    OSSIA/ossia/editor/curve/curve_segment.hpp \
    OSSIA/ossia/editor/dataspace/detail/dataspace_convert.hpp \
    OSSIA/ossia/editor/dataspace/detail/dataspace_merge.hpp \
    OSSIA/ossia/editor/dataspace/detail/dataspace_parse.hpp \
    OSSIA/ossia/editor/dataspace/detail/make_unit.hpp \
    OSSIA/ossia/editor/dataspace/detail/make_value.hpp \
    OSSIA/ossia/editor/dataspace/angle.hpp \
    OSSIA/ossia/editor/dataspace/color.hpp \
    OSSIA/ossia/editor/dataspace/dataspace.hpp \
    OSSIA/ossia/editor/dataspace/dataspace_base.hpp \
    OSSIA/ossia/editor/dataspace/dataspace_base_fwd.hpp \
    OSSIA/ossia/editor/dataspace/dataspace_fwd.hpp \
    OSSIA/ossia/editor/dataspace/dataspace_parse.hpp \
    OSSIA/ossia/editor/dataspace/dataspace_visitors.hpp \
    OSSIA/ossia/editor/dataspace/distance.hpp \
    OSSIA/ossia/editor/dataspace/gain.hpp \
    OSSIA/ossia/editor/dataspace/orientation.hpp \
    OSSIA/ossia/editor/dataspace/position.hpp \
    OSSIA/ossia/editor/dataspace/speed.hpp \
    OSSIA/ossia/editor/dataspace/temperature.hpp \
    OSSIA/ossia/editor/dataspace/time.hpp \
    OSSIA/ossia/editor/dataspace/value_with_unit.hpp \
    OSSIA/ossia/editor/expression/expression.hpp \
    OSSIA/ossia/editor/expression/expression_atom.hpp \
    OSSIA/ossia/editor/expression/expression_bool.hpp \
    OSSIA/ossia/editor/expression/expression_composition.hpp \
    OSSIA/ossia/editor/expression/expression_fwd.hpp \
    OSSIA/ossia/editor/expression/expression_generic.hpp \
    OSSIA/ossia/editor/expression/expression_not.hpp \
    OSSIA/ossia/editor/expression/expression_pulse.hpp \
    OSSIA/ossia/editor/expression/operators.hpp \
    OSSIA/ossia/editor/loop/loop.hpp \
    OSSIA/ossia/editor/mapper/mapper.hpp \
    OSSIA/ossia/editor/scenario/clock.hpp \
    OSSIA/ossia/editor/scenario/scenario.hpp \
    OSSIA/ossia/editor/scenario/time_constraint.hpp \
    OSSIA/ossia/editor/scenario/time_event.hpp \
    OSSIA/ossia/editor/scenario/time_node.hpp \
    OSSIA/ossia/editor/scenario/time_process.hpp \
    OSSIA/ossia/editor/scenario/time_value.hpp \
    OSSIA/ossia/editor/state/detail/state_execution_visitor.hpp \
    OSSIA/ossia/editor/state/detail/state_flatten_visitor.hpp \
    OSSIA/ossia/editor/state/detail/state_print_visitor.hpp \
    OSSIA/ossia/editor/state/custom_state.hpp \
    OSSIA/ossia/editor/state/destination_qualifiers.hpp \
    OSSIA/ossia/editor/state/functional_state.hpp \
    OSSIA/ossia/editor/state/message.hpp \
    OSSIA/ossia/editor/state/state.hpp \
    OSSIA/ossia/editor/state/state_element.hpp \
    OSSIA/ossia/editor/state/state_element_fwd.hpp \
    OSSIA/ossia/editor/value/detail/value_conversion_impl.hpp \
    OSSIA/ossia/editor/value/destination.hpp \
    OSSIA/ossia/editor/value/impulse.hpp \
    OSSIA/ossia/editor/value/value.hpp \
    OSSIA/ossia/editor/value/value_algorithms.hpp \
    OSSIA/ossia/editor/value/value_base.hpp \
    OSSIA/ossia/editor/value/value_comparison.hpp \
    OSSIA/ossia/editor/value/value_conversion.hpp \
    OSSIA/ossia/editor/value/value_traits.hpp \
    OSSIA/ossia/editor/value/vec.hpp \
    OSSIA/ossia/editor/editor.hpp \
    OSSIA/ossia/editor/exceptions.hpp \
    OSSIA/ossia/network/base/address.hpp \
    OSSIA/ossia/network/base/address_data.hpp \
    OSSIA/ossia/network/base/device.hpp \
    OSSIA/ossia/network/base/listening.hpp \
    OSSIA/ossia/network/base/name_validation.hpp \
    OSSIA/ossia/network/base/node.hpp \
    OSSIA/ossia/network/base/node_attributes.hpp \
    OSSIA/ossia/network/base/protocol.hpp \
    OSSIA/ossia/network/base/value_callback.hpp \
    OSSIA/ossia/network/common/address_properties.hpp \
    OSSIA/ossia/network/common/complex_type.hpp \
    OSSIA/ossia/network/common/debug.hpp \
    OSSIA/ossia/network/common/extended_types.hpp \
    OSSIA/ossia/network/common/network_logger.hpp \
    OSSIA/ossia/network/common/path.hpp \
    OSSIA/ossia/network/common/websocket_log_sink.hpp \
    OSSIA/ossia/network/domain/detail/apply_domain.hpp \
    OSSIA/ossia/network/domain/detail/array_domain.hpp \
    OSSIA/ossia/network/domain/detail/clamp_visitors.hpp \
    OSSIA/ossia/network/domain/detail/generic_domain.hpp \
    OSSIA/ossia/network/domain/detail/min_max.hpp \
    OSSIA/ossia/network/domain/detail/numeric_domain.hpp \
    OSSIA/ossia/network/domain/detail/value_set_domain.hpp \
    OSSIA/ossia/network/domain/domain.hpp \
    OSSIA/ossia/network/domain/domain_base.hpp \
    OSSIA/ossia/network/domain/domain_conversion.hpp \
    OSSIA/ossia/network/domain/domain_functions.hpp \
    OSSIA/ossia/network/domain/domain_fwd.hpp \
    OSSIA/ossia/network/generic/alias_node.hpp \
    OSSIA/ossia/network/generic/generic_address.hpp \
    OSSIA/ossia/network/generic/generic_device.hpp \
    OSSIA/ossia/network/generic/generic_node.hpp \
    OSSIA/ossia/network/local/local.hpp \
    OSSIA/ossia/network/midi/detail/channel.hpp \
    OSSIA/ossia/network/midi/detail/midi_impl.hpp \
    OSSIA/ossia/network/midi/midi.hpp \
    OSSIA/ossia/network/midi/midi_address.hpp \
    OSSIA/ossia/network/midi/midi_device.hpp \
    OSSIA/ossia/network/midi/midi_node.hpp \
    OSSIA/ossia/network/midi/midi_protocol.hpp \
    OSSIA/ossia/network/minuit/detail/minuit_common.hpp \
    OSSIA/ossia/network/minuit/detail/minuit_name_table.hpp \
    OSSIA/ossia/network/minuit/detail/minuit_parser.hpp \
    OSSIA/ossia/network/minuit/minuit.hpp \
    OSSIA/ossia/network/osc/detail/message_generator.hpp \
    OSSIA/ossia/network/osc/detail/osc.hpp \
    OSSIA/ossia/network/osc/detail/receiver.hpp \
    OSSIA/ossia/network/osc/detail/sender.hpp \
    OSSIA/ossia/network/osc/detail/string_view.hpp \
    OSSIA/ossia/network/osc/osc.hpp \
    OSSIA/ossia/network/oscquery/detail/attributes.hpp \
    OSSIA/ossia/network/oscquery/detail/client.hpp \
    OSSIA/ossia/network/oscquery/detail/domain_to_json.hpp \
    OSSIA/ossia/network/oscquery/detail/get_query_parser.hpp \
    OSSIA/ossia/network/oscquery/detail/http_client.hpp \
    OSSIA/ossia/network/oscquery/detail/http_query_parser.hpp \
    OSSIA/ossia/network/oscquery/detail/json_parser.hpp \
    OSSIA/ossia/network/oscquery/detail/json_query_parser.hpp \
    OSSIA/ossia/network/oscquery/detail/json_reader_detail.hpp \
    OSSIA/ossia/network/oscquery/detail/json_writer.hpp \
    OSSIA/ossia/network/oscquery/detail/json_writer_detail.hpp \
    OSSIA/ossia/network/oscquery/detail/query_parser.hpp \
    OSSIA/ossia/network/oscquery/detail/server.hpp \
    OSSIA/ossia/network/oscquery/detail/typetag.hpp \
    OSSIA/ossia/network/oscquery/detail/value_to_json.hpp \
    OSSIA/ossia/network/oscquery/oscquery_client.hpp \
    OSSIA/ossia/network/oscquery/oscquery_mirror.hpp \
    OSSIA/ossia/network/oscquery/oscquery_server.hpp \
    OSSIA/ossia/network/zeroconf/zeroconf.hpp \
    OSSIA/ossia/network/exceptions.hpp \
    OSSIA/ossia/network/network.hpp \
    OSSIA/ossia/context.hpp \
    OSSIA/ossia/ossia.hpp \
    OSSIA/ossia/prefix.hpp \
    OSSIA/ossia-qt/device/qml_device.hpp \
    OSSIA/ossia-qt/device/qml_node.hpp \
    OSSIA/ossia-qt/device/qml_node_base.hpp \
    OSSIA/ossia-qt/device/qml_property.hpp \
    OSSIA/ossia-qt/device/qt_device.hpp \
    OSSIA/ossia-qt/device/qt_object_node.hpp \
    OSSIA/ossia-qt/device/qt_property_node.hpp \
    OSSIA/ossia-qt/http/http.hpp \
    OSSIA/ossia-qt/http/http_address.hpp \
    OSSIA/ossia-qt/http/http_address_data.hpp \
    OSSIA/ossia-qt/http/http_device.hpp \
    OSSIA/ossia-qt/http/http_node.hpp \
    OSSIA/ossia-qt/http/http_protocol.hpp \
    OSSIA/ossia-qt/serial/serial.hpp \
    OSSIA/ossia-qt/serial/serial_address.hpp \
    OSSIA/ossia-qt/serial/serial_address_data.hpp \
    OSSIA/ossia-qt/serial/serial_device.hpp \
    OSSIA/ossia-qt/serial/serial_node.hpp \
    OSSIA/ossia-qt/serial/serial_protocol.hpp \
    OSSIA/ossia-qt/websocket-generic-client/ws_generic_client.hpp \
    OSSIA/ossia-qt/websocket-generic-client/ws_generic_client_address.hpp \
    OSSIA/ossia-qt/websocket-generic-client/ws_generic_client_address_data.hpp \
    OSSIA/ossia-qt/websocket-generic-client/ws_generic_client_device.hpp \
    OSSIA/ossia-qt/websocket-generic-client/ws_generic_client_node.hpp \
    OSSIA/ossia-qt/websocket-generic-client/ws_generic_client_protocol.hpp \
    OSSIA/ossia-qt/js_utilities.hpp \
    OSSIA/ossia-qt/metatypes.hpp \
    OSSIA/ossia-qt/qml_plugin.hpp \
    OSSIA/ossia-qt/value_metatypes.hpp
