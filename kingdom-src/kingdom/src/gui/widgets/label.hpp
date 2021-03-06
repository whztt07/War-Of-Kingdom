/* $Id: label.hpp 54038 2012-04-30 19:37:24Z mordante $ */
/*
   Copyright (C) 2008 - 2012 by Mark de Wever <koraq@xs4all.nl>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

#ifndef GUI_WIDGETS_LABEL_HPP_INCLUDED
#define GUI_WIDGETS_LABEL_HPP_INCLUDED

#include "gui/widgets/control.hpp"

namespace gui2 {

/** Label showing a text. */
class tlabel : public tcontrol
{
public:

	tlabel()
		: tcontrol(COUNT)
		, state_(ENABLED)
		, can_wrap_(false)
		, characters_per_line_(0)
		, best_size_(0, 0)
	{
	}

	/***** ***** ***** ***** layout functions ***** ***** ***** *****/

private:
	/** Inherited from tcontrol. */
	tpoint calculate_best_size() const
	{
		return best_size_ != tpoint(0, 0)
			? best_size_ : tcontrol::calculate_best_size();
	}

public:
	/** Inherited from twidget. */
	bool can_wrap() const;

	/** Inherited from tcontrol. */
	unsigned get_characters_per_line() const;

	/** Inherited from tcontrol. */
	void set_active(const bool active)
		{ if(get_active() != active) set_state(active ? ENABLED : DISABLED); }

	/** Inherited from tcontrol. */
	bool get_active() const { return state_ != DISABLED; }

	/** Inherited from tcontrol. */
	unsigned get_state() const { return state_; }

	/** Inherited from tcontrol. */
	bool disable_click_dismiss() const { return false; }

	/***** ***** ***** setters / getters for members ***** ****** *****/

	void set_can_wrap(const bool wrap) { can_wrap_ = wrap; }

	void set_characters_per_line(const unsigned set_characters_per_line);

	void set_best_size(const tpoint& best_size) { best_size_ = best_size; }
private:

	/**
	 * Possible states of the widget.
	 *
	 * Note the order of the states must be the same as defined in settings.hpp.
	 */
	enum tstate { ENABLED, DISABLED, COUNT };

	void set_state(const tstate state);

	/**
	 * Current state of the widget.
	 *
	 * The state of the widget determines what to render and how the widget
	 * reacts to certain 'events'.
	 */
	tstate state_;

	/** Holds the label can wrap or not. */
	bool can_wrap_;

	/**
	 * The maximum number of characters per line.
	 *
	 * The maximum is not an exact maximum, it uses the average character width.
	 */
	unsigned characters_per_line_;

	/** When we're used as a fixed size item, this holds the best size. */
	tpoint best_size_;

	/** Inherited from tcontrol. */
	const std::string& get_control_type() const;
};

} // namespace gui2

#endif

