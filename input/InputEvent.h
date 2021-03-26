/*
 * ControlEvent.h
 *
 *  Created on: Aug 22, 2020
 *      Author: ghisi
 */

#ifndef INPUT_INPUTEVENT_H_
#define INPUT_INPUTEVENT_H_

enum class InputEvent {
	none,
	dialPlus,
	dialMinus,
	dialPushButtonPressed,
	dialPushButtonReleased,
	padUpPressed,
	padUpReleased,
	padDownPressed,
	padDownReleased,
	padLeftPressed,
	padLeftReleased,
	padRightPressed,
	padRightReleased,
	padEnterPressed,
	padEnterReleased
};

#endif /* INPUT_INPUTEVENT_H_ */
