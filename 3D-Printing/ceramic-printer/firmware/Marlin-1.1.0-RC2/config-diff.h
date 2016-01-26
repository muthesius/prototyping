diff --git a/Marlin/Configuration.h b/Marlin/example_configurations/delta/generic/Configuration.h
index 5da249f..84f18c0 100755
--- a/Marlin/Configuration.h
+++ b/Marlin/example_configurations/delta/generic/Configuration.h
@@ -75,7 +75,7 @@ Here are some standard links for getting your machine calibrated:
 
 // Optional custom name for your RepStrap or other custom machine
 // Displayed in the LCD "Ready" message
-//#define CUSTOM_MACHINE_NAME "3D Printer"
+#define CUSTOM_MACHINE_NAME "Deltabot"
 
 // Define this to set a unique identifier for this printer, (Used by some programs to differentiate between machines)
 // You can use an online service to generate a random UUID. (eg http://www.uuidgenerator.net/version4)
@@ -145,8 +145,8 @@ Here are some standard links for getting your machine calibrated:
 //#define DUMMY_THERMISTOR_998_VALUE 25
 //#define DUMMY_THERMISTOR_999_VALUE 100
 // :{ '0': "Not used", '4': "10k !! do not use for a hotend. Bad resolution at high temp. !!", '1': "100k / 4.7k - EPCOS", '51': "100k / 1k - EPCOS", '6': "100k / 4.7k EPCOS - Not as accurate as Table 1", '5': "100K / 4.7k - ATC Semitec 104GT-2 (Used in ParCan & J-Head)", '7': "100k / 4.7k Honeywell 135-104LAG-J01", '71': "100k / 4.7k Honeywell 135-104LAF-J01", '8': "100k / 4.7k 0603 SMD Vishay NTCS0603E3104FXT", '9': "100k / 4.7k GE Sensing AL03006-58.2K-97-G1", '10': "100k / 4.7k RS 198-961", '11': "100k / 4.7k beta 3950 1%", '12': "100k / 4.7k 0603 SMD Vishay NTCS0603E3104FXT (calibrated for Makibox hot bed)", '13': "100k Hisens 3950  1% up to 300°C for hotend 'Simple ONE ' & hotend 'All In ONE'", '60': "100k Maker's Tool Works Kapton Bed Thermistor beta=3950", '55': "100k / 1k - ATC Semitec 104GT-2 (Used in ParCan & J-Head)", '2': "200k / 4.7k - ATC Semitec 204GT-2", '52': "200k / 1k - ATC Semitec 204GT-2", '-2': "Thermocouple + MAX6675 (only for sensor 0)", '-1': "Thermocouple + AD595", '3': "Mendel-parts / 4.7k", '1047': "Pt1000 / 4.7k", '1010': "Pt1000 / 1k (non standard)", '20': "PT100 (Ultimainboard V2.x)", '147': "Pt100 / 4.7k", '110': "Pt100 / 1k (non-standard)", '998': "Dummy 1", '999': "Dummy 2" }
-#define TEMP_SENSOR_0 1
-#define TEMP_SENSOR_1 0
+#define TEMP_SENSOR_0 -1
+#define TEMP_SENSOR_1 -1
 #define TEMP_SENSOR_2 0
 #define TEMP_SENSOR_3 0
 #define TEMP_SENSOR_BED 0
@@ -311,6 +311,41 @@ Here are some standard links for getting your machine calibrated:
 // Uncomment this option to enable CoreXZ kinematics
 //#define COREXZ
 
+//===========================================================================
+//============================== Delta Settings =============================
+//===========================================================================
+// Enable DELTA kinematics and most of the default configuration for Deltas
+#define DELTA
+
+#if ENABLED(DELTA)
+
+  // Make delta curves from many straight lines (linear interpolation).
+  // This is a trade-off between visible corners (not enough segments)
+  // and processor overload (too many expensive sqrt calls).
+  #define DELTA_SEGMENTS_PER_SECOND 200
+
+  // NOTE NB all values for DELTA_* values MUST be floating point, so always have a decimal point in them
+
+  // Center-to-center distance of the holes in the diagonal push rods.
+  #define DELTA_DIAGONAL_ROD 250.0 // mm
+
+  // Horizontal offset from middle of printer to smooth rod center.
+  #define DELTA_SMOOTH_ROD_OFFSET 175.0 // mm
+
+  // Horizontal offset of the universal joints on the end effector.
+  #define DELTA_EFFECTOR_OFFSET 33.0 // mm
+
+  // Horizontal offset of the universal joints on the carriages.
+  #define DELTA_CARRIAGE_OFFSET 18.0 // mm
+
+  // Horizontal distance bridged by diagonal push rods when effector is centered.
+  #define DELTA_RADIUS (DELTA_SMOOTH_ROD_OFFSET-DELTA_EFFECTOR_OFFSET-DELTA_CARRIAGE_OFFSET)
+
+  // Print surface diameter/2 minus unreachable space (avoid collisions with vertical towers).
+  #define DELTA_PRINTABLE_RADIUS 140
+
+#endif
+
 // Enable this option for Toshiba steppers
 //#define CONFIG_STEPPERS_TOSHIBA
 
@@ -331,15 +366,15 @@ Here are some standard links for getting your machine calibrated:
 #endif
 
 // Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
-const bool X_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
-const bool Y_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
-const bool Z_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
-const bool X_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
-const bool Y_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
-const bool Z_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
-const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
+const bool X_MIN_ENDSTOP_INVERTING = true; // set to true to invert the logic of the endstop.
+const bool Y_MIN_ENDSTOP_INVERTING = true; // set to true to invert the logic of the endstop.
+const bool Z_MIN_ENDSTOP_INVERTING = true; // set to true to invert the logic of the endstop.
+const bool X_MAX_ENDSTOP_INVERTING = true; // set to true to invert the logic of the endstop.
+const bool Y_MAX_ENDSTOP_INVERTING = true; // set to true to invert the logic of the endstop.
+const bool Z_MAX_ENDSTOP_INVERTING = true; // set to true to invert the logic of the endstop.
+const bool Z_MIN_PROBE_ENDSTOP_INVERTING = true; // set to true to invert the logic of the endstop.
 //#define DISABLE_MAX_ENDSTOPS
-//#define DISABLE_MIN_ENDSTOPS
+#define DISABLE_MIN_ENDSTOPS // Deltas only use min endstops for probing.
 
 // If you want to enable the Z probe pin, but disable its use, uncomment the line below.
 // This only affects a Z probe endstop if you have separate Z min endstop as well and have
@@ -368,8 +403,8 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 // @section machine
 
 // Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
-#define INVERT_X_DIR false
-#define INVERT_Y_DIR true
+#define INVERT_X_DIR false // DELTA does not invert
+#define INVERT_Y_DIR false
 #define INVERT_Z_DIR false
 
 // @section extruder
@@ -385,9 +420,9 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 // ENDSTOP SETTINGS:
 // Sets direction of endstops when homing; 1=MAX, -1=MIN
 // :[-1,1]
-#define X_HOME_DIR -1
-#define Y_HOME_DIR -1
-#define Z_HOME_DIR -1
+#define X_HOME_DIR 1  // deltas always home to max
+#define Y_HOME_DIR 1
+#define Z_HOME_DIR 1
 
 #define min_software_endstops true // If true, axis won't move to coordinates less than HOME_POS.
 #define max_software_endstops true  // If true, axis won't move to coordinates greater than the defined lengths below.
@@ -395,12 +430,12 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 // @section machine
 
 // Travel limits after homing (units are in mm)
-#define X_MIN_POS 0
-#define Y_MIN_POS 0
+#define X_MIN_POS -DELTA_PRINTABLE_RADIUS
+#define Y_MIN_POS -DELTA_PRINTABLE_RADIUS
 #define Z_MIN_POS 0
-#define X_MAX_POS 200
-#define Y_MAX_POS 200
-#define Z_MAX_POS 200
+#define X_MAX_POS DELTA_PRINTABLE_RADIUS
+#define Y_MAX_POS DELTA_PRINTABLE_RADIUS
+#define Z_MAX_POS MANUAL_Z_HOME_POS
 
 //===========================================================================
 //========================= Filament Runout Sensor ==========================
@@ -442,13 +477,14 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 
 // @section bedlevel
 
+
 //#define AUTO_BED_LEVELING_FEATURE // Delete the comment to enable (remove // at the start of the line)
 //#define DEBUG_LEVELING_FEATURE
-#define Z_MIN_PROBE_REPEATABILITY_TEST  // If not commented out, Z-Probe Repeatability test will be included if Auto Bed Leveling is Enabled.
+//#define Z_MIN_PROBE_REPEATABILITY_TEST  // If not commented out, Z-Probe Repeatability test will be included if Auto Bed Leveling is Enabled.
 
 #if ENABLED(AUTO_BED_LEVELING_FEATURE)
 
-  // There are 2 different ways to specify probing locations:
+  // There are 2 different ways to specify probing locations.
   //
   // - "grid" mode
   //   Probe several points in a rectangular grid.
@@ -461,20 +497,24 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 
   // Enable this to sample the bed in a grid (least squares solution).
   // Note: this feature generates 10KB extra code size.
-  #define AUTO_BED_LEVELING_GRID
+  #define AUTO_BED_LEVELING_GRID  // Deltas only support grid mode.
 
   #if ENABLED(AUTO_BED_LEVELING_GRID)
 
-    #define LEFT_PROBE_BED_POSITION 15
-    #define RIGHT_PROBE_BED_POSITION 170
-    #define FRONT_PROBE_BED_POSITION 20
-    #define BACK_PROBE_BED_POSITION 170
+    // set the rectangle in which to probe
+    #define DELTA_PROBABLE_RADIUS (DELTA_PRINTABLE_RADIUS - 10)
+    #define LEFT_PROBE_BED_POSITION -DELTA_PROBABLE_RADIUS
+    #define RIGHT_PROBE_BED_POSITION DELTA_PROBABLE_RADIUS
+    #define FRONT_PROBE_BED_POSITION -DELTA_PROBABLE_RADIUS
+    #define BACK_PROBE_BED_POSITION DELTA_PROBABLE_RADIUS
 
-    #define MIN_PROBE_EDGE 10 // The Z probe minimum square sides can be no smaller than this.
+    #define MIN_PROBE_EDGE 10 // The Z probe square sides can be no smaller than this.
 
-    // Set the number of grid points per dimension.
-    // You probably don't need more than 3 (squared=9).
-    #define AUTO_BED_LEVELING_GRID_POINTS 2
+    // Non-linear bed leveling will be used.
+    // Compensate by interpolating between the nearest four Z probe values for each point.
+    // Useful for deltas where the print surface may appear like a bowl or dome shape.
+    // Works best with ACCURATE_BED_LEVELING_POINTS 5 or higher.
+    #define AUTO_BED_LEVELING_GRID_POINTS 9
 
   #else  // !AUTO_BED_LEVELING_GRID
 
@@ -491,18 +531,18 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 
   // Offsets to the Z probe relative to the nozzle tip.
   // X and Y offsets must be integers.
-  #define X_PROBE_OFFSET_FROM_EXTRUDER -25     // Z probe to nozzle X offset: -left  +right
-  #define Y_PROBE_OFFSET_FROM_EXTRUDER -29     // Z probe to nozzle Y offset: -front +behind
-  #define Z_PROBE_OFFSET_FROM_EXTRUDER -12.35  // Z probe to nozzle Z offset: -below (always!)
+  #define X_PROBE_OFFSET_FROM_EXTRUDER 0     // Z probe to nozzle X offset: -left  +right
+  #define Y_PROBE_OFFSET_FROM_EXTRUDER -10   // Z probe to nozzle Y offset: -front +behind
+  #define Z_PROBE_OFFSET_FROM_EXTRUDER -3.5  // Z probe to nozzle Z offset: -below (always!)
 
   #define Z_RAISE_BEFORE_HOMING 4       // (in mm) Raise Z axis before homing (G28) for Z probe clearance.
                                         // Be sure you have this distance over your Z_MAX_POS in case.
 
-  #define XY_TRAVEL_SPEED 8000         // X and Y axis travel speed between probes, in mm/min.
+  #define XY_TRAVEL_SPEED 4000         // X and Y axis travel speed between probes, in mm/min.
 
   #define Z_RAISE_BEFORE_PROBING 15   // How much the Z axis will be raised before traveling to the first probing point.
-  #define Z_RAISE_BETWEEN_PROBINGS 5  // How much the Z axis will be raised when traveling from between next probing points.
-  #define Z_RAISE_AFTER_PROBING 15    // How much the Z axis will be raised after the last probing point.
+  #define Z_RAISE_BETWEEN_PROBINGS 5  // How much the Z axis will be raised when traveling from between next probing points
+  #define Z_RAISE_AFTER_PROBING 50    // How much the Z axis will be raised after the last probing point.
 
 //#define Z_PROBE_END_SCRIPT "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10" // These commands will be executed in the end of G29 routine.
                                                                             // Useful to retract a deployable Z probe.
@@ -510,9 +550,89 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
   //#define Z_PROBE_SLED // Turn on if you have a Z probe mounted on a sled like those designed by Charles Bell.
   //#define SLED_DOCKING_OFFSET 5 // The extra distance the X axis must travel to pickup the sled. 0 should be fine but you can push it further if you'd like.
 
+  // Allen key retractable z-probe as seen on many Kossel delta printers - http://reprap.org/wiki/Kossel#Automatic_bed_leveling_probe
+  // Deploys by touching z-axis belt. Retracts by pushing the probe down. Uses Z_MIN_PIN.
+  //#define Z_PROBE_ALLEN_KEY
+
+  #if ENABLED(Z_PROBE_ALLEN_KEY)
+    // 2 or 3 sets of coordinates for deploying and retracting the spring loaded touch probe on G29,
+    // if servo actuated touch probe is not defined. Uncomment as appropriate for your printer/probe.
+
+    #define Z_PROBE_ALLEN_KEY_DEPLOY_1_X 30.0
+    #define Z_PROBE_ALLEN_KEY_DEPLOY_1_Y DELTA_PRINTABLE_RADIUS
+    #define Z_PROBE_ALLEN_KEY_DEPLOY_1_Z 100.0
+    #define Z_PROBE_ALLEN_KEY_DEPLOY_1_FEEDRATE HOMING_FEEDRATE_XYZ
+    #define Z_PROBE_ALLEN_KEY_DEPLOY_2_X 0.0
+    #define Z_PROBE_ALLEN_KEY_DEPLOY_2_Y DELTA_PRINTABLE_RADIUS
+    #define Z_PROBE_ALLEN_KEY_DEPLOY_2_Z 100.0
+    #define Z_PROBE_ALLEN_KEY_DEPLOY_2_FEEDRATE (HOMING_FEEDRATE_XYZ/10)
+
+    #define Z_PROBE_ALLEN_KEY_STOW_1_X -64.0 // Move the probe into position
+    #define Z_PROBE_ALLEN_KEY_STOW_1_Y 56.0
+    #define Z_PROBE_ALLEN_KEY_STOW_1_Z 23.0
+    #define Z_PROBE_ALLEN_KEY_STOW_1_FEEDRATE HOMING_FEEDRATE_XYZ
+    #define Z_PROBE_ALLEN_KEY_STOW_2_X -64.0 // Push it down
+    #define Z_PROBE_ALLEN_KEY_STOW_2_Y 56.0
+    #define Z_PROBE_ALLEN_KEY_STOW_2_Z 3.0
+    #define Z_PROBE_ALLEN_KEY_STOW_2_FEEDRATE (HOMING_FEEDRATE_XYZ/10)
+    #define Z_PROBE_ALLEN_KEY_STOW_3_X -64.0 // Move it up to clear
+    #define Z_PROBE_ALLEN_KEY_STOW_3_Y 56.0
+    #define Z_PROBE_ALLEN_KEY_STOW_3_Z 50.0
+    #define Z_PROBE_ALLEN_KEY_STOW_3_FEEDRATE HOMING_FEEDRATE_XYZ
+
+    // Kossel Mini
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_1_X 35.0
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_1_Y 72.0
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_1_Z 100.0
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_1_FEEDRATE (HOMING_FEEDRATE_XYZ/10)
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_2_X 0.0
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_2_Y 0.0
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_2_Z 100.0
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_2_FEEDRATE (HOMING_FEEDRATE_XYZ/10)
+
+    //#define Z_PROBE_ALLEN_KEY_STOW_1_X -46.0 // Move the probe into position
+    //#define Z_PROBE_ALLEN_KEY_STOW_1_Y 59.0
+    //#define Z_PROBE_ALLEN_KEY_STOW_1_Z 28.0
+    //#define Z_PROBE_ALLEN_KEY_STOW_1_FEEDRATE HOMING_FEEDRATE_XYZ
+    //#define Z_PROBE_ALLEN_KEY_STOW_2_X -46.0 // Move the nozzle down further to push the probe into retracted position.
+    //#define Z_PROBE_ALLEN_KEY_STOW_2_Y 59.0
+    //#define Z_PROBE_ALLEN_KEY_STOW_2_Z 8.0
+    //#define Z_PROBE_ALLEN_KEY_STOW_2_FEEDRATE (HOMING_FEEDRATE_XYZ/10)
+    //#define Z_PROBE_ALLEN_KEY_STOW_3_X -46.0 // Raise things back up slightly so we don't bump into anything
+    //#define Z_PROBE_ALLEN_KEY_STOW_3_Y 59.0
+    //#define Z_PROBE_ALLEN_KEY_STOW_3_Z 38.0
+    //#define Z_PROBE_ALLEN_KEY_STOW_3_FEEDRATE HOMING_FEEDRATE_XYZ
+
+    // Kossel Pro
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_1_X -105.00 // Move left but not quite so far that we'll bump the belt
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_1_Y 0.00
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_1_Z 100.0
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_1_FEEDRATE HOMING_FEEDRATE_XYZ
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_2_X -110.00 // Move outward to position deploy pin to the left of the arm
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_2_Y -125.00
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_2_Z 100.0
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_2_FEEDRATE HOMING_FEEDRATE_XYZ
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_3_X 45.00 // Move right to trigger deploy pin
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_3_Y -125.00
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_3_Z 100.0
+    //#define Z_PROBE_ALLEN_KEY_DEPLOY_3_FEEDRATE (HOMING_FEEDRATE_XYZ/2)
+
+    //#define Z_PROBE_ALLEN_KEY_STOW_1_X 36.00 // Line up with bed retaining clip
+    //#define Z_PROBE_ALLEN_KEY_STOW_1_Y -122.00
+    //#define Z_PROBE_ALLEN_KEY_STOW_1_Z 75.0
+    //#define Z_PROBE_ALLEN_KEY_STOW_1_FEEDRATE HOMING_FEEDRATE_XYZ
+    //#define Z_PROBE_ALLEN_KEY_STOW_2_X 36.00 // move down to retract probe
+    //#define Z_PROBE_ALLEN_KEY_STOW_2_Y -122.00
+    //#define Z_PROBE_ALLEN_KEY_STOW_2_Z 25.0
+    //#define Z_PROBE_ALLEN_KEY_STOW_2_FEEDRATE (HOMING_FEEDRATE_XYZ/2)
+    //#define Z_PROBE_ALLEN_KEY_STOW_3_X 0.0  // return to 0,0,100
+    //#define Z_PROBE_ALLEN_KEY_STOW_3_Y 0.0
+    //#define Z_PROBE_ALLEN_KEY_STOW_3_Z 100.0
+    //#define Z_PROBE_ALLEN_KEY_STOW_3_FEEDRATE HOMING_FEEDRATE_XYZ
+  #endif
 
-  //If you have enabled the Bed Auto Leveling and are using the same Z Probe for Z Homing,
-  //it is highly recommended you let this Z_SAFE_HOMING enabled!!!
+// If you have enabled the bed auto leveling and are using the same Z probe for Z homing,
+// it is highly recommended you let this Z_SAFE_HOMING enabled!!!
 
   #define Z_SAFE_HOMING   // This feature is meant to avoid Z homing with Z probe outside the bed area.
                           // When defined, it will:
@@ -565,7 +685,7 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 // @section homing
 
 // The position of the homing switches
-//#define MANUAL_HOME_POSITIONS  // If defined, MANUAL_*_HOME_POS below will be used
+#define MANUAL_HOME_POSITIONS  // If defined, MANUAL_*_HOME_POS below will be used
 //#define BED_CENTER_AT_0_0  // If defined, the center of the bed is at (X=0, Y=0)
 
 // Manual homing switch locations:
@@ -573,8 +693,7 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 #if ENABLED(MANUAL_HOME_POSITIONS)
   #define MANUAL_X_HOME_POS 0
   #define MANUAL_Y_HOME_POS 0
-  #define MANUAL_Z_HOME_POS 0
-  //#define MANUAL_Z_HOME_POS 402 // For delta: Distance between nozzle and print surface after homing.
+  #define MANUAL_Z_HOME_POS 250 // For delta: Distance between nozzle and print surface after homing.
 #endif
 
 // @section movement
@@ -583,13 +702,16 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
  * MOVEMENT SETTINGS
  */
 
-#define HOMING_FEEDRATE {50*60, 50*60, 4*60, 0}  // set the homing speeds (mm/min)
+// delta homing speeds must be the same on xyz
+#define HOMING_FEEDRATE_XYZ (200*60)
+#define HOMING_FEEDRATE_E 0
+#define HOMING_FEEDRATE { HOMING_FEEDRATE_XYZ, HOMING_FEEDRATE_XYZ, HOMING_FEEDRATE_XYZ, HOMING_FEEDRATE_E }
 
 // default settings
-
-#define DEFAULT_AXIS_STEPS_PER_UNIT   {80,80,4000,500}  // default steps per unit for Ultimaker
-#define DEFAULT_MAX_FEEDRATE          {300, 300, 5, 25}    // (mm/sec)
-#define DEFAULT_MAX_ACCELERATION      {3000,3000,100,10000}    // X, Y, Z, E maximum start speed for accelerated moves. E default values are good for Skeinforge 40+, for older versions raise them a lot.
+// delta speeds must be the same on xyz
+#define DEFAULT_AXIS_STEPS_PER_UNIT   {80, 80, 80, 760*1.1}  // default steps per unit for Kossel (GT2, 20 tooth)
+#define DEFAULT_MAX_FEEDRATE          {500, 500, 500, 25}    // (mm/sec)
+#define DEFAULT_MAX_ACCELERATION      {9000,9000,9000,10000}    // X, Y, Z, E maximum start speed for accelerated moves. E default values are good for skeinforge 40+, for older versions raise them a lot.
 
 #define DEFAULT_ACCELERATION          3000    // X, Y, Z and E acceleration in mm/s^2 for printing moves
 #define DEFAULT_RETRACT_ACCELERATION  3000    // E acceleration in mm/s^2 for retracts
@@ -597,8 +719,8 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 
 // The speed change that does not require acceleration (i.e. the software might assume it can be done instantaneously)
 #define DEFAULT_XYJERK                20.0    // (mm/sec)
-#define DEFAULT_ZJERK                 0.4     // (mm/sec)
-#define DEFAULT_EJERK                 5.0    // (mm/sec)
+#define DEFAULT_ZJERK                 20.0    // (mm/sec) Must be same as XY for delta
+#define DEFAULT_EJERK                 5.0     // (mm/sec)
 
 
 //=============================================================================
@@ -642,11 +764,11 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 // Preheat Constants
 #define PLA_PREHEAT_HOTEND_TEMP 180
 #define PLA_PREHEAT_HPB_TEMP 70
-#define PLA_PREHEAT_FAN_SPEED 0   // Insert Value between 0 and 255
+#define PLA_PREHEAT_FAN_SPEED 255   // Insert Value between 0 and 255
 
 #define ABS_PREHEAT_HOTEND_TEMP 240
-#define ABS_PREHEAT_HPB_TEMP 110
-#define ABS_PREHEAT_FAN_SPEED 0   // Insert Value between 0 and 255
+#define ABS_PREHEAT_HPB_TEMP 100
+#define ABS_PREHEAT_FAN_SPEED 255   // Insert Value between 0 and 255
 
 //==============================LCD and SD support=============================
 // @section lcd
@@ -722,6 +844,13 @@ const bool Z_MIN_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the l
 // REMEMBER TO INSTALL LiquidCrystal_I2C.h in your ARDUINO library folder: https://github.com/kiyoshigawa/LiquidCrystal_I2C
 //#define RA_CONTROL_PANEL
 
+// Delta calibration menu
+// uncomment to add three points calibration menu option.
+// See http://minow.blogspot.com/index.html#4918805519571907051
+// If needed, adjust the X, Y, Z calibration coordinates
+// in ultralcd.cpp@lcd_delta_calibrate_menu()
+//#define DELTA_CALIBRATION_MENU
+
 // The MakerLab Mini Panel with graphic controller and SD support
 // http://reprap.org/wiki/Mini_panel
 //#define MINIPANEL
