
//
// @COPYRIGHT@
//
// $Id: ActiveUseValueSwitch.java,v 1.2 2004/12/22 23:39:06 archiecobbs Exp $
//

package org.dellroad.jc.cgen.analysis;

import soot.jimple.*;
import soot.grimp.AbstractGrimpValueSwitch;
import soot.grimp.NewInvokeExpr;
import soot.toolkits.scalar.FlowSet;

/**
 * Determine the SootClass which will definitely be initialized after
 * evaluating the value, if any.
 */
public class ActiveUseValueSwitch extends AbstractGrimpValueSwitch {

	public void caseNewInvokeExpr(NewInvokeExpr v) {
		setResult(v.getMethod().getDeclaringClass());
	}

	public void caseSpecialInvokeExpr(SpecialInvokeExpr v) {
		setResult(v.getMethod().getDeclaringClass());
	}

	public void caseStaticInvokeExpr(StaticInvokeExpr v) {
		setResult(v.getMethod().getDeclaringClass());
	}

	public void caseVirtualInvokeExpr(VirtualInvokeExpr v) {
		setResult(v.getMethod().getDeclaringClass());
	}

	public void caseNewExpr(NewExpr v) {
		setResult(v.getBaseType().getSootClass());
	}

	public void caseInstanceFieldRef(InstanceFieldRef v) {
		setResult(v.getField().getDeclaringClass());
	}

	public void caseStaticFieldRef(StaticFieldRef v) {
		setResult(v.getField().getDeclaringClass());
	}
}

