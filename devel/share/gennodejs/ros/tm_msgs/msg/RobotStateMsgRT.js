// Auto-generated. Do not edit!

// (in-package tm_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class RobotStateMsgRT {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.time = null;
      this.controller_time = null;
      this.q_command = null;
      this.qd_command = null;
      this.qt_command = null;
      this.q_actual = null;
      this.qd_actual = null;
      this.qt_actual = null;
      this.tool0_pos_command = null;
      this.tool0_pos_actual = null;
      this.tool_pos_command = null;
      this.tool_pos_actual = null;
      this.tcp_speed = null;
      this.tcp_force = null;
      this.kine_config = null;
      this.common_speed_ratio = null;
      this.robot_mode = null;
      this.safety_mode = null;
      this.teach_mode = null;
      this.control_mode = null;
      this.error_code_0 = null;
      this.error_code_1 = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0.0;
      }
      if (initObj.hasOwnProperty('controller_time')) {
        this.controller_time = initObj.controller_time
      }
      else {
        this.controller_time = 0.0;
      }
      if (initObj.hasOwnProperty('q_command')) {
        this.q_command = initObj.q_command
      }
      else {
        this.q_command = [];
      }
      if (initObj.hasOwnProperty('qd_command')) {
        this.qd_command = initObj.qd_command
      }
      else {
        this.qd_command = [];
      }
      if (initObj.hasOwnProperty('qt_command')) {
        this.qt_command = initObj.qt_command
      }
      else {
        this.qt_command = [];
      }
      if (initObj.hasOwnProperty('q_actual')) {
        this.q_actual = initObj.q_actual
      }
      else {
        this.q_actual = [];
      }
      if (initObj.hasOwnProperty('qd_actual')) {
        this.qd_actual = initObj.qd_actual
      }
      else {
        this.qd_actual = [];
      }
      if (initObj.hasOwnProperty('qt_actual')) {
        this.qt_actual = initObj.qt_actual
      }
      else {
        this.qt_actual = [];
      }
      if (initObj.hasOwnProperty('tool0_pos_command')) {
        this.tool0_pos_command = initObj.tool0_pos_command
      }
      else {
        this.tool0_pos_command = [];
      }
      if (initObj.hasOwnProperty('tool0_pos_actual')) {
        this.tool0_pos_actual = initObj.tool0_pos_actual
      }
      else {
        this.tool0_pos_actual = [];
      }
      if (initObj.hasOwnProperty('tool_pos_command')) {
        this.tool_pos_command = initObj.tool_pos_command
      }
      else {
        this.tool_pos_command = [];
      }
      if (initObj.hasOwnProperty('tool_pos_actual')) {
        this.tool_pos_actual = initObj.tool_pos_actual
      }
      else {
        this.tool_pos_actual = [];
      }
      if (initObj.hasOwnProperty('tcp_speed')) {
        this.tcp_speed = initObj.tcp_speed
      }
      else {
        this.tcp_speed = [];
      }
      if (initObj.hasOwnProperty('tcp_force')) {
        this.tcp_force = initObj.tcp_force
      }
      else {
        this.tcp_force = [];
      }
      if (initObj.hasOwnProperty('kine_config')) {
        this.kine_config = initObj.kine_config
      }
      else {
        this.kine_config = [];
      }
      if (initObj.hasOwnProperty('common_speed_ratio')) {
        this.common_speed_ratio = initObj.common_speed_ratio
      }
      else {
        this.common_speed_ratio = 0.0;
      }
      if (initObj.hasOwnProperty('robot_mode')) {
        this.robot_mode = initObj.robot_mode
      }
      else {
        this.robot_mode = 0;
      }
      if (initObj.hasOwnProperty('safety_mode')) {
        this.safety_mode = initObj.safety_mode
      }
      else {
        this.safety_mode = 0;
      }
      if (initObj.hasOwnProperty('teach_mode')) {
        this.teach_mode = initObj.teach_mode
      }
      else {
        this.teach_mode = 0;
      }
      if (initObj.hasOwnProperty('control_mode')) {
        this.control_mode = initObj.control_mode
      }
      else {
        this.control_mode = 0;
      }
      if (initObj.hasOwnProperty('error_code_0')) {
        this.error_code_0 = initObj.error_code_0
      }
      else {
        this.error_code_0 = 0;
      }
      if (initObj.hasOwnProperty('error_code_1')) {
        this.error_code_1 = initObj.error_code_1
      }
      else {
        this.error_code_1 = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RobotStateMsgRT
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [time]
    bufferOffset = _serializer.float64(obj.time, buffer, bufferOffset);
    // Serialize message field [controller_time]
    bufferOffset = _serializer.float64(obj.controller_time, buffer, bufferOffset);
    // Serialize message field [q_command]
    bufferOffset = _arraySerializer.float64(obj.q_command, buffer, bufferOffset, null);
    // Serialize message field [qd_command]
    bufferOffset = _arraySerializer.float64(obj.qd_command, buffer, bufferOffset, null);
    // Serialize message field [qt_command]
    bufferOffset = _arraySerializer.float64(obj.qt_command, buffer, bufferOffset, null);
    // Serialize message field [q_actual]
    bufferOffset = _arraySerializer.float64(obj.q_actual, buffer, bufferOffset, null);
    // Serialize message field [qd_actual]
    bufferOffset = _arraySerializer.float64(obj.qd_actual, buffer, bufferOffset, null);
    // Serialize message field [qt_actual]
    bufferOffset = _arraySerializer.float64(obj.qt_actual, buffer, bufferOffset, null);
    // Serialize message field [tool0_pos_command]
    bufferOffset = _arraySerializer.float64(obj.tool0_pos_command, buffer, bufferOffset, null);
    // Serialize message field [tool0_pos_actual]
    bufferOffset = _arraySerializer.float64(obj.tool0_pos_actual, buffer, bufferOffset, null);
    // Serialize message field [tool_pos_command]
    bufferOffset = _arraySerializer.float64(obj.tool_pos_command, buffer, bufferOffset, null);
    // Serialize message field [tool_pos_actual]
    bufferOffset = _arraySerializer.float64(obj.tool_pos_actual, buffer, bufferOffset, null);
    // Serialize message field [tcp_speed]
    bufferOffset = _arraySerializer.float64(obj.tcp_speed, buffer, bufferOffset, null);
    // Serialize message field [tcp_force]
    bufferOffset = _arraySerializer.float64(obj.tcp_force, buffer, bufferOffset, null);
    // Serialize message field [kine_config]
    bufferOffset = _arraySerializer.int32(obj.kine_config, buffer, bufferOffset, null);
    // Serialize message field [common_speed_ratio]
    bufferOffset = _serializer.float64(obj.common_speed_ratio, buffer, bufferOffset);
    // Serialize message field [robot_mode]
    bufferOffset = _serializer.int32(obj.robot_mode, buffer, bufferOffset);
    // Serialize message field [safety_mode]
    bufferOffset = _serializer.int32(obj.safety_mode, buffer, bufferOffset);
    // Serialize message field [teach_mode]
    bufferOffset = _serializer.int32(obj.teach_mode, buffer, bufferOffset);
    // Serialize message field [control_mode]
    bufferOffset = _serializer.int32(obj.control_mode, buffer, bufferOffset);
    // Serialize message field [error_code_0]
    bufferOffset = _serializer.int32(obj.error_code_0, buffer, bufferOffset);
    // Serialize message field [error_code_1]
    bufferOffset = _serializer.int32(obj.error_code_1, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RobotStateMsgRT
    let len;
    let data = new RobotStateMsgRT(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [time]
    data.time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [controller_time]
    data.controller_time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [q_command]
    data.q_command = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [qd_command]
    data.qd_command = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [qt_command]
    data.qt_command = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [q_actual]
    data.q_actual = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [qd_actual]
    data.qd_actual = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [qt_actual]
    data.qt_actual = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [tool0_pos_command]
    data.tool0_pos_command = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [tool0_pos_actual]
    data.tool0_pos_actual = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [tool_pos_command]
    data.tool_pos_command = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [tool_pos_actual]
    data.tool_pos_actual = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [tcp_speed]
    data.tcp_speed = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [tcp_force]
    data.tcp_force = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [kine_config]
    data.kine_config = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [common_speed_ratio]
    data.common_speed_ratio = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [robot_mode]
    data.robot_mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [safety_mode]
    data.safety_mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [teach_mode]
    data.teach_mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [control_mode]
    data.control_mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [error_code_0]
    data.error_code_0 = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [error_code_1]
    data.error_code_1 = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 8 * object.q_command.length;
    length += 8 * object.qd_command.length;
    length += 8 * object.qt_command.length;
    length += 8 * object.q_actual.length;
    length += 8 * object.qd_actual.length;
    length += 8 * object.qt_actual.length;
    length += 8 * object.tool0_pos_command.length;
    length += 8 * object.tool0_pos_actual.length;
    length += 8 * object.tool_pos_command.length;
    length += 8 * object.tool_pos_actual.length;
    length += 8 * object.tcp_speed.length;
    length += 8 * object.tcp_force.length;
    length += 4 * object.kine_config.length;
    return length + 100;
  }

  static datatype() {
    // Returns string type for a message object
    return 'tm_msgs/RobotStateMsgRT';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b44d2ec991068109b7dfd7a73666f138';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Data structure for the realtime communications interface
    # used by the Techman Robot controller
    # 
    # This data structure is send at 100 Hz on TCP port 6188
    
    Header header
    float64 time
    float64 controller_time
    float64[] q_command
    float64[] qd_command
    float64[] qt_command
    float64[] q_actual
    float64[] qd_actual
    float64[] qt_actual
    float64[] tool0_pos_command
    float64[] tool0_pos_actual
    float64[] tool_pos_command
    float64[] tool_pos_actual
    float64[] tcp_speed
    float64[] tcp_force
    int32[] kine_config
    float64 common_speed_ratio
    int32 robot_mode
    int32 safety_mode
    int32 teach_mode
    int32 control_mode
    int32 error_code_0
    int32 error_code_1
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RobotStateMsgRT(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0.0
    }

    if (msg.controller_time !== undefined) {
      resolved.controller_time = msg.controller_time;
    }
    else {
      resolved.controller_time = 0.0
    }

    if (msg.q_command !== undefined) {
      resolved.q_command = msg.q_command;
    }
    else {
      resolved.q_command = []
    }

    if (msg.qd_command !== undefined) {
      resolved.qd_command = msg.qd_command;
    }
    else {
      resolved.qd_command = []
    }

    if (msg.qt_command !== undefined) {
      resolved.qt_command = msg.qt_command;
    }
    else {
      resolved.qt_command = []
    }

    if (msg.q_actual !== undefined) {
      resolved.q_actual = msg.q_actual;
    }
    else {
      resolved.q_actual = []
    }

    if (msg.qd_actual !== undefined) {
      resolved.qd_actual = msg.qd_actual;
    }
    else {
      resolved.qd_actual = []
    }

    if (msg.qt_actual !== undefined) {
      resolved.qt_actual = msg.qt_actual;
    }
    else {
      resolved.qt_actual = []
    }

    if (msg.tool0_pos_command !== undefined) {
      resolved.tool0_pos_command = msg.tool0_pos_command;
    }
    else {
      resolved.tool0_pos_command = []
    }

    if (msg.tool0_pos_actual !== undefined) {
      resolved.tool0_pos_actual = msg.tool0_pos_actual;
    }
    else {
      resolved.tool0_pos_actual = []
    }

    if (msg.tool_pos_command !== undefined) {
      resolved.tool_pos_command = msg.tool_pos_command;
    }
    else {
      resolved.tool_pos_command = []
    }

    if (msg.tool_pos_actual !== undefined) {
      resolved.tool_pos_actual = msg.tool_pos_actual;
    }
    else {
      resolved.tool_pos_actual = []
    }

    if (msg.tcp_speed !== undefined) {
      resolved.tcp_speed = msg.tcp_speed;
    }
    else {
      resolved.tcp_speed = []
    }

    if (msg.tcp_force !== undefined) {
      resolved.tcp_force = msg.tcp_force;
    }
    else {
      resolved.tcp_force = []
    }

    if (msg.kine_config !== undefined) {
      resolved.kine_config = msg.kine_config;
    }
    else {
      resolved.kine_config = []
    }

    if (msg.common_speed_ratio !== undefined) {
      resolved.common_speed_ratio = msg.common_speed_ratio;
    }
    else {
      resolved.common_speed_ratio = 0.0
    }

    if (msg.robot_mode !== undefined) {
      resolved.robot_mode = msg.robot_mode;
    }
    else {
      resolved.robot_mode = 0
    }

    if (msg.safety_mode !== undefined) {
      resolved.safety_mode = msg.safety_mode;
    }
    else {
      resolved.safety_mode = 0
    }

    if (msg.teach_mode !== undefined) {
      resolved.teach_mode = msg.teach_mode;
    }
    else {
      resolved.teach_mode = 0
    }

    if (msg.control_mode !== undefined) {
      resolved.control_mode = msg.control_mode;
    }
    else {
      resolved.control_mode = 0
    }

    if (msg.error_code_0 !== undefined) {
      resolved.error_code_0 = msg.error_code_0;
    }
    else {
      resolved.error_code_0 = 0
    }

    if (msg.error_code_1 !== undefined) {
      resolved.error_code_1 = msg.error_code_1;
    }
    else {
      resolved.error_code_1 = 0
    }

    return resolved;
    }
};

module.exports = RobotStateMsgRT;
