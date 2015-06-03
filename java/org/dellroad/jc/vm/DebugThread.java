
//
// @COPYRIGHT@
//
// $Id: DebugThread.java,v 1.1.1.1 2004/02/20 05:15:26 archiecobbs Exp $
//

package org.dellroad.jc.vm;

/**
 * JC debug thread. This thread sits and waits for SIGUSR1 signals.
 * When one is received, it spits out the status and Java stack traces
 * of all threads, as well as information about all class loaders.
 */
class DebugThread extends Thread {

	DebugThread() {
		super("debug");
		setPriority(MIN_PRIORITY);
	}

	public void run() {
		while (true) {
			waitForInterrupt();
			dumpDebugInfo();
		}
	}

	// VM will call Thread.interrupt() on this thread when SIGUR1 rec'd
	synchronized void waitForInterrupt() {
		try {
			wait();
		} catch (InterruptedException e) {
		}
	}

	static native void dumpDebugInfo();
}

