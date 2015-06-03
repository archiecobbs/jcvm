
//
// @COPYRIGHT@
//
// $Id: StackAlloc.java,v 1.2 2004/12/17 15:35:46 archiecobbs Exp $
//

package org.dellroad.jc.cgen.escape;

import java.util.*;
import soot.*;
import soot.jimple.*;

/**
 * Holds information about a potential stack-allocatable 'new' statement.
 */
class StackAlloc {

	AssignStmt stmt;
	Local local;
	Value value;		// the 'new' expression
	Boolean escapes; 	// TRUE = yes, FALSE = no, null = unknown
	int size;
	int cost;

	public StackAlloc(Stmt ostmt) {
		this.stmt = (AssignStmt)ostmt;
		this.local = (Local)stmt.getLeftOp();
		this.value = stmt.getRightOp();
	}
}

