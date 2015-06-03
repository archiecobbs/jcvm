
//
// @COPYRIGHT@
//
// $Id: ActiveUseTag.java,v 1.1 2004/12/19 21:01:04 archiecobbs Exp $
//

package org.dellroad.jc.cgen.analysis;

import soot.tagkit.Tag;

/**
 * Tag for ``first active use'' class initialization checks.
 */
public class ActiveUseTag implements Tag {

	private final static String NAME = "ActiveUseTag";

	private final static ActiveUseTag NEEDED = new ActiveUseTag(true);
	private final static ActiveUseTag NOT_NEEDED = new ActiveUseTag(false);

	private final boolean checkNeeded;

	public ActiveUseTag(boolean checkNeeded) {
		this.checkNeeded = checkNeeded;
	}

	public boolean isCheckNeeded() {
		return checkNeeded;
	}

	public byte[] getValue() {
		return new byte[] { checkNeeded ? (byte)1 : (byte)0 };
	}

	public String getName() {
		return NAME;
	}

	public String toString() {
		return NAME;
	}

	public static ActiveUseTag v(boolean checkNeeded) {
		return checkNeeded ? NEEDED : NOT_NEEDED;
	}
}

