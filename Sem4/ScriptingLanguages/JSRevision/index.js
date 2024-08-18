import t from "@studio-freight/lenis";
function s() {
    return s = Object.assign ? Object.assign.bind() : function (t2) {
        for (var s2 = 1; s2 < arguments.length; s2++) {
            var e2 = arguments[s2];
            for (var i2 in e2)
                Object.prototype.hasOwnProperty.call(e2, i2) && (t2[i2] = e2[i2]);
        }
        return t2;
    }, s.apply(this, arguments);
}
class e {
    constructor({ scrollElements: t2, rootMargin: s2 = "-1px -1px -1px -1px", IORaf: e2 }) {
        this.scrollElements = void 0, this.rootMargin = void 0, this.IORaf = void 0, this.observer = void 0, this.scrollElements = t2, this.rootMargin = s2, this.IORaf = e2, this._init();
    }
    _init() {
        this.observer = new IntersectionObserver((t2) => {
            t2.forEach((t3) => {
                const s2 = this.scrollElements.find((s3) => s3.$el === t3.target);
                t3.isIntersecting ? (s2 && (s2.isAlreadyIntersected = true), this._setInview(t3)) : s2 && s2.isAlreadyIntersected && this._setOutOfView(t3);
            });
        }, { rootMargin: this.rootMargin });
        for (const t2 of this.scrollElements)
            this.observe(t2.$el);
    }
    destroy() {
        this.observer.disconnect();
    }
    observe(t2) {
        t2 && this.observer.observe(t2);
    }
    unobserve(t2) {
        t2 && this.observer.unobserve(t2);
    }
    _setInview(t2) {
        const s2 = this.scrollElements.find((s3) => s3.$el === t2.target);
        this.IORaf && (s2 == null || s2.setInteractivityOn()), !this.IORaf && (s2 == null || s2.setInview());
    }
    _setOutOfView(t2) {
        const s2 = this.scrollElements.find((s3) => s3.$el === t2.target);
        this.IORaf && (s2 == null || s2.setInteractivityOff()), !this.IORaf && (s2 == null || s2.setOutOfView()), s2 != null && s2.attributes.scrollRepeat || this.IORaf || this.unobserve(t2.target);
    }
}
function i(t2, s2, e2, i2, r2) {
    return e2 + ((r2 - t2) / (s2 - t2) * (i2 - e2) || 0);
}
function r(t2, s2) {
    return t2.reduce((t3, e2) => Math.abs(e2 - s2) < Math.abs(t3 - s2) ? e2 : t3);
}
class l {
    constructor({ $el: t2, id: s2, modularInstance: e2, subscribeElementUpdateFn: i2, unsubscribeElementUpdateFn: r2, needRaf: l2, scrollOrientation: n2 }) {
        var o2, a2, c2, h2, d;
        this.$el = void 0, this.id = void 0, this.needRaf = void 0, this.attributes = void 0, this.scrollOrientation = void 0, this.isAlreadyIntersected = void 0, this.intersection = void 0, this.metrics = void 0, this.currentScroll = void 0, this.translateValue = void 0, this.progress = void 0, this.lastProgress = void 0, this.modularInstance = void 0, this.progressModularModules = void 0, this.isInview = void 0, this.isInteractive = void 0, this.isInFold = void 0, this.isFirstResize = void 0, this.subscribeElementUpdateFn = void 0, this.unsubscribeElementUpdateFn = void 0, this.$el = t2, this.id = s2, this.needRaf = l2, this.scrollOrientation = n2, this.modularInstance = e2, this.subscribeElementUpdateFn = i2, this.unsubscribeElementUpdateFn = r2, this.attributes = { scrollClass: (o2 = this.$el.dataset.scrollClass) != null ? o2 : "is-inview", scrollOffset: (a2 = this.$el.dataset.scrollOffset) != null ? a2 : "0,0", scrollPosition: (c2 = this.$el.dataset.scrollPosition) != null ? c2 : "start,end", scrollModuleProgress: this.$el.dataset.scrollModuleProgress != null, scrollCssProgress: this.$el.dataset.scrollCssProgress != null, scrollEventProgress: (h2 = this.$el.dataset.scrollEventProgress) != null ? h2 : null, scrollSpeed: this.$el.dataset.scrollSpeed != null ? parseFloat(this.$el.dataset.scrollSpeed) : null, scrollRepeat: this.$el.dataset.scrollRepeat != null, scrollCall: (d = this.$el.dataset.scrollCall) != null ? d : null, scrollCallSelf: this.$el.dataset.scrollCallSelf != null, scrollIgnoreFold: this.$el.dataset.scrollIgnoreFold != null, scrollEnableTouchSpeed: this.$el.dataset.scrollEnableTouchSpeed != null }, this.intersection = { start: 0, end: 0 }, this.metrics = { offsetStart: 0, offsetEnd: 0, bcr: {} }, this.currentScroll = this.scrollOrientation === "vertical" ? window.scrollY : window.scrollX, this.translateValue = 0, this.progress = 0, this.lastProgress = null, this.progressModularModules = [], this.isInview = false, this.isInteractive = false, this.isAlreadyIntersected = false, this.isInFold = false, this.isFirstResize = true, this._init();
    }
    _init() {
        this.needRaf && (this.modularInstance && this.attributes.scrollModuleProgress && this._getProgressModularModules(), this._resize());
    }
    onResize({ currentScroll: t2 }) {
        this.currentScroll = t2, this._resize();
    }
    onRender({ currentScroll: t2, smooth: s2 }) {
        const e2 = this.scrollOrientation === "vertical" ? window.innerHeight : window.innerWidth;
        if (this.currentScroll = t2, this._computeProgress(), this.attributes.scrollSpeed && !isNaN(this.attributes.scrollSpeed))
            if (this.attributes.scrollEnableTouchSpeed || s2) {
                if (this.isInFold) {
                    const t3 = Math.max(0, this.progress);
                    this.translateValue = t3 * e2 * this.attributes.scrollSpeed * -1;
                } else {
                    const t3 = i(0, 1, -1, 1, this.progress);
                    this.translateValue = t3 * e2 * this.attributes.scrollSpeed * -1;
                }
                this.$el.style.transform = this.scrollOrientation === "vertical" ? `translate3d(0, ${this.translateValue}px, 0)` : `translate3d(${this.translateValue}px, 0, 0)`;
            } else
                this.translateValue && (this.$el.style.transform = "translate3d(0, 0, 0)"), this.translateValue = 0;
    }
    setInview() {
        if (this.isInview)
            return;
        this.isInview = true, this.$el.classList.add(this.attributes.scrollClass);
        const t2 = this._getScrollCallFrom();
        this.attributes.scrollCall && this._dispatchCall("enter", t2);
    }
    setOutOfView() {
        if (!this.isInview || !this.attributes.scrollRepeat)
            return;
        this.isInview = false, this.$el.classList.remove(this.attributes.scrollClass);
        const t2 = this._getScrollCallFrom();
        this.attributes.scrollCall && this._dispatchCall("leave", t2);
    }
    setInteractivityOn() {
        this.isInteractive || (this.isInteractive = true, this.subscribeElementUpdateFn(this));
    }
    setInteractivityOff() {
        this.isInteractive && (this.isInteractive = false, this.unsubscribeElementUpdateFn(this), this.lastProgress != null && this._computeProgress(r([0, 1], this.lastProgress)));
    }
    _resize() {
        this.metrics.bcr = this.$el.getBoundingClientRect(), this._computeMetrics(), this._computeIntersection(), this.isFirstResize && (this.isFirstResize = false, this.isInFold && this.setInview());
    }
    _computeMetrics() {
        const { top: t2, left: s2, height: e2, width: i2 } = this.metrics.bcr, r2 = this.scrollOrientation === "vertical" ? window.innerHeight : window.innerWidth, l2 = this.scrollOrientation === "vertical" ? e2 : i2;
        this.metrics.offsetStart = this.currentScroll + (this.scrollOrientation === "vertical" ? t2 : s2) - this.translateValue, this.metrics.offsetEnd = this.metrics.offsetStart + l2, this.isInFold = this.metrics.offsetStart < r2 && !this.attributes.scrollIgnoreFold;
    }
    _computeIntersection() {
        const t2 = this.scrollOrientation === "vertical" ? window.innerHeight : window.innerWidth, s2 = this.scrollOrientation === "vertical" ? this.metrics.bcr.height : this.metrics.bcr.width, e2 = this.attributes.scrollOffset.split(","), i2 = e2[0] != null ? e2[0].trim() : "0", r2 = e2[1] != null ? e2[1].trim() : "0", l2 = this.attributes.scrollPosition.split(",");
        let n2 = l2[0] != null ? l2[0].trim() : "start";
        const o2 = l2[1] != null ? l2[1].trim() : "end", a2 = i2.includes("%") ? t2 * parseInt(i2.replace("%", "").trim()) * 0.01 : parseInt(i2), c2 = r2.includes("%") ? t2 * parseInt(r2.replace("%", "").trim()) * 0.01 : parseInt(r2);
        switch (this.isInFold && (n2 = "fold"), n2) {
            case "start":
            default:
                this.intersection.start = this.metrics.offsetStart - t2 + a2;
                break;
            case "middle":
                this.intersection.start = this.metrics.offsetStart - t2 + a2 + 0.5 * s2;
                break;
            case "end":
                this.intersection.start = this.metrics.offsetStart - t2 + a2 + s2;
                break;
            case "fold":
                this.intersection.start = 0;
        }
        switch (o2) {
            case "start":
                this.intersection.end = this.metrics.offsetStart - c2;
                break;
            case "middle":
                this.intersection.end = this.metrics.offsetStart - c2 + 0.5 * s2;
                break;
            default:
                this.intersection.end = this.metrics.offsetStart - c2 + s2;
        }
        if (this.intersection.end <= this.intersection.start)
            switch (o2) {
                case "start":
                default:
                    this.intersection.end = this.intersection.start + 1;
                    break;
                case "middle":
                    this.intersection.end = this.intersection.start + 0.5 * s2;
                    break;
                case "end":
                    this.intersection.end = this.intersection.start + s2;
            }
    }
    _computeProgress(t2) {
        const s2 = t2 != null ? t2 : (e2 = i(this.intersection.start, this.intersection.end, 0, 1, this.currentScroll)) < 0 ? 0 : e2 > 1 ? 1 : e2;
        var e2;
        if (this.progress = s2, s2 != this.lastProgress) {
            if (this.lastProgress = s2, this.attributes.scrollCssProgress && this._setCssProgress(s2), this.attributes.scrollEventProgress && this._setCustomEventProgress(s2), this.attributes.scrollModuleProgress)
                for (const t3 of this.progressModularModules)
                    this.modularInstance && this.modularInstance.call("onScrollProgress", s2, t3.moduleName, t3.moduleId);
            s2 > 0 && s2 < 1 && this.setInview(), s2 === 0 && this.setOutOfView(), s2 === 1 && this.setOutOfView();
        }
    }
    _setCssProgress(t2 = 0) {
        this.$el.style.setProperty("--progress", t2.toString());
    }
    _setCustomEventProgress(t2 = 0) {
        const s2 = this.attributes.scrollEventProgress;
        if (!s2)
            return;
        const e2 = new CustomEvent(s2, { detail: { target: this.$el, progress: t2 } });
        window.dispatchEvent(e2);
    }
    _getProgressModularModules() {
        if (!this.modularInstance)
            return;
        const t2 = Object.keys(this.$el.dataset).filter((t3) => t3.includes("module")), s2 = Object.entries(this.modularInstance.modules);
        if (t2.length)
            for (const e2 of t2) {
                const t3 = this.$el.dataset[e2];
                if (!t3)
                    return;
                for (const e3 of s2) {
                    const [s3, i2] = e3;
                    t3 in i2 && this.progressModularModules.push({ moduleName: s3, moduleId: t3 });
                }
            }
    }
    _getScrollCallFrom() {
        const t2 = r([this.intersection.start, this.intersection.end], this.currentScroll);
        return this.intersection.start === t2 ? "start" : "end";
    }
    _dispatchCall(t2, s2) {
        var e2, i2;
        const r2 = (e2 = this.attributes.scrollCall) == null ? void 0 : e2.split(","), l2 = (i2 = this.attributes) == null ? void 0 : i2.scrollCallSelf;
        if (r2 && r2.length > 1) {
            var n2;
            const [e3, i3, o2] = r2;
            let a2;
            a2 = l2 ? this.$el.dataset[`module${i3.trim()}`] : o2, this.modularInstance && this.modularInstance.call(e3.trim(), { target: this.$el, way: t2, from: s2 }, i3.trim(), (n2 = a2) == null ? void 0 : n2.trim());
        } else if (r2) {
            const [e3] = r2, i3 = new CustomEvent(e3, { detail: { target: this.$el, way: t2, from: s2 } });
            window.dispatchEvent(i3);
        }
    }
}
const n = ["scrollOffset", "scrollPosition", "scrollModuleProgress", "scrollCssProgress", "scrollEventProgress", "scrollSpeed"];
class o {
    constructor({ $el: t2, modularInstance: s2, triggerRootMargin: e2, rafRootMargin: i2, scrollOrientation: r2 }) {
        this.$scrollContainer = void 0, this.modularInstance = void 0, this.triggerRootMargin = void 0, this.rafRootMargin = void 0, this.scrollElements = void 0, this.triggeredScrollElements = void 0, this.RAFScrollElements = void 0, this.scrollElementsToUpdate = void 0, this.IOTriggerInstance = void 0, this.IORafInstance = void 0, this.scrollOrientation = void 0, t2 ? (this.$scrollContainer = t2, this.modularInstance = s2, this.scrollOrientation = r2, this.triggerRootMargin = e2 != null ? e2 : "-1px -1px -1px -1px", this.rafRootMargin = i2 != null ? i2 : "100% 100% 100% 100%", this.scrollElements = [], this.triggeredScrollElements = [], this.RAFScrollElements = [], this.scrollElementsToUpdate = [], this._init()) : console.error("Please provide a DOM Element as scrollContainer");
    }
    _init() {
        const t2 = this.$scrollContainer.querySelectorAll("[data-scroll]"), s2 = Array.from(t2);
        this._subscribeScrollElements(s2), this.IOTriggerInstance = new e({ scrollElements: [...this.triggeredScrollElements], rootMargin: this.triggerRootMargin, IORaf: false }), this.IORafInstance = new e({ scrollElements: [...this.RAFScrollElements], rootMargin: this.rafRootMargin, IORaf: true });
    }
    destroy() {
        this.IOTriggerInstance.destroy(), this.IORafInstance.destroy(), this._unsubscribeAllScrollElements();
    }
    onResize({ currentScroll: t2 }) {
        for (const s2 of this.RAFScrollElements)
            s2.onResize({ currentScroll: t2 });
    }
    onRender({ currentScroll: t2, smooth: s2 }) {
        for (const e2 of this.scrollElementsToUpdate)
            e2.onRender({ currentScroll: t2, smooth: s2 });
    }
    removeScrollElements(t2) {
        const s2 = t2.querySelectorAll("[data-scroll]");
        if (s2.length) {
            for (let t3 = 0; t3 < this.triggeredScrollElements.length; t3++) {
                const e2 = this.triggeredScrollElements[t3];
                Array.from(s2).indexOf(e2.$el) > -1 && (this.IOTriggerInstance.unobserve(e2.$el), this.triggeredScrollElements.splice(t3, 1));
            }
            for (let t3 = 0; t3 < this.RAFScrollElements.length; t3++) {
                const e2 = this.RAFScrollElements[t3];
                Array.from(s2).indexOf(e2.$el) > -1 && (this.IORafInstance.unobserve(e2.$el), this.RAFScrollElements.splice(t3, 1));
            }
            s2.forEach((t3) => {
                const s3 = this.scrollElementsToUpdate.find((s4) => s4.$el === t3), e2 = this.scrollElements.find((s4) => s4.$el === t3);
                s3 && this._unsubscribeElementUpdate(s3), e2 && (this.scrollElements = this.scrollElements.filter((t4) => t4.id != e2.id));
            });
        }
    }
    addScrollElements(t2) {
        const s2 = t2.querySelectorAll("[data-scroll]"), e2 = [];
        this.scrollElements.forEach((t3) => {
            e2.push(t3.id);
        });
        const i2 = Math.max(...e2) + 1, r2 = Array.from(s2);
        this._subscribeScrollElements(r2, i2, true);
    }
    _subscribeScrollElements(t2, s2 = 0, e2 = false) {
        for (let i2 = 0; i2 < t2.length; i2++) {
            const r2 = t2[i2], n2 = this._checkRafNeeded(r2), o2 = new l({ $el: r2, id: s2 + i2, scrollOrientation: this.scrollOrientation, modularInstance: this.modularInstance, subscribeElementUpdateFn: this._subscribeElementUpdate.bind(this), unsubscribeElementUpdateFn: this._unsubscribeElementUpdate.bind(this), needRaf: n2 });
            this.scrollElements.push(o2), n2 ? (this.RAFScrollElements.push(o2), e2 && (this.IORafInstance.scrollElements.push(o2), this.IORafInstance.observe(o2.$el))) : (this.triggeredScrollElements.push(o2), e2 && (this.IOTriggerInstance.scrollElements.push(o2), this.IOTriggerInstance.observe(o2.$el)));
        }
    }
    _unsubscribeAllScrollElements() {
        this.scrollElements = [], this.RAFScrollElements = [], this.triggeredScrollElements = [], this.scrollElementsToUpdate = [];
    }
    _subscribeElementUpdate(t2) {
        this.scrollElementsToUpdate.push(t2);
    }
    _unsubscribeElementUpdate(t2) {
        this.scrollElementsToUpdate = this.scrollElementsToUpdate.filter((s2) => s2.id != t2.id);
    }
    _checkRafNeeded(t2) {
        let s2 = [...n];
        const e2 = (t3) => {
            s2 = s2.filter((s3) => s3 != t3);
        };
        if (t2.dataset.scrollOffset) {
            if (t2.dataset.scrollOffset.split(",").map((t3) => t3.replace("%", "").trim()).join(",") != "0,0")
                return true;
            e2("scrollOffset");
        } else
            e2("scrollOffset");
        if (t2.dataset.scrollPosition) {
            if (t2.dataset.scrollPosition.trim() != "top,bottom")
                return true;
            e2("scrollPosition");
        } else
            e2("scrollPosition");
        if (t2.dataset.scrollSpeed && !isNaN(parseFloat(t2.dataset.scrollSpeed)))
            return true;
        e2("scrollSpeed");
        for (const e3 of s2)
            if (e3 in t2.dataset)
                return true;
        return false;
    }
}
class a {
    constructor({ resizeElements: t2, resizeCallback: s2 = () => {
    } }) {
        this.$resizeElements = void 0, this.isFirstObserve = void 0, this.observer = void 0, this.resizeCallback = void 0, this.$resizeElements = t2, this.resizeCallback = s2, this.isFirstObserve = true, this._init();
    }
    _init() {
        this.observer = new ResizeObserver((t2) => {
            var s2;
            !this.isFirstObserve && ((s2 = this.resizeCallback) == null || s2.call(this)), this.isFirstObserve = false;
        });
        for (const t2 of this.$resizeElements)
            this.observer.observe(t2);
    }
    destroy() {
        this.observer.disconnect();
    }
}
const c = { wrapper: window, content: document.documentElement, eventsTarget: window, lerp: 0.1, duration: 0.75, orientation: "vertical", gestureOrientation: "vertical", smoothWheel: true, smoothTouch: false, syncTouch: false, syncTouchLerp: 0.1, touchInertiaMultiplier: 35, wheelMultiplier: 1, touchMultiplier: 2, normalizeWheel: false, autoResize: true, easing: (t2) => Math.min(1, 1.001 - Math.pow(2, -10 * t2)) };
class h {
    constructor({ lenisOptions: t2 = {}, modularInstance: e2, triggerRootMargin: i2, rafRootMargin: r2, autoResize: l2 = true, autoStart: n2 = true, scrollCallback: o2 = () => {
    }, initCustomTicker: a2, destroyCustomTicker: h2 } = {}) {
        this.rafPlaying = void 0, this.lenisInstance = void 0, this.coreInstance = void 0, this.lenisOptions = void 0, this.modularInstance = void 0, this.triggerRootMargin = void 0, this.rafRootMargin = void 0, this.rafInstance = void 0, this.autoResize = void 0, this.autoStart = void 0, this.ROInstance = void 0, this.initCustomTicker = void 0, this.destroyCustomTicker = void 0, this._onRenderBind = void 0, this._onResizeBind = void 0, this._onScrollToBind = void 0, this.lenisOptions = s({}, c, t2), Object.assign(this, { lenisOptions: t2, modularInstance: e2, triggerRootMargin: i2, rafRootMargin: r2, autoResize: l2, autoStart: n2, scrollCallback: o2, initCustomTicker: a2, destroyCustomTicker: h2 }), this._onRenderBind = this._onRender.bind(this), this._onScrollToBind = this._onScrollTo.bind(this), this._onResizeBind = this._onResize.bind(this), this.rafPlaying = false, this._init();
    }
    _init() {
        var s2;
        this.lenisInstance = new t({ wrapper: this.lenisOptions.wrapper, content: this.lenisOptions.content, eventsTarget: this.lenisOptions.eventsTarget, lerp: this.lenisOptions.lerp, duration: this.lenisOptions.duration, orientation: this.lenisOptions.orientation, gestureOrientation: this.lenisOptions.gestureOrientation, smoothWheel: this.lenisOptions.smoothWheel, smoothTouch: this.lenisOptions.smoothTouch, syncTouch: this.lenisOptions.syncTouch, syncTouchLerp: this.lenisOptions.syncTouchLerp, touchInertiaMultiplier: this.lenisOptions.touchInertiaMultiplier, wheelMultiplier: this.lenisOptions.wheelMultiplier, touchMultiplier: this.lenisOptions.touchMultiplier, normalizeWheel: this.lenisOptions.normalizeWheel, easing: this.lenisOptions.easing }), (s2 = this.lenisInstance) == null || s2.on("scroll", this.scrollCallback), document.documentElement.setAttribute("data-scroll-orientation", this.lenisInstance.options.orientation), requestAnimationFrame(() => {
            this.coreInstance = new o({ $el: this.lenisInstance.rootElement, modularInstance: this.modularInstance, triggerRootMargin: this.triggerRootMargin, rafRootMargin: this.rafRootMargin, scrollOrientation: this.lenisInstance.options.orientation }), this._bindEvents(), this.initCustomTicker && !this.destroyCustomTicker ? console.warn("initCustomTicker callback is declared, but destroyCustomTicker is not. Please pay attention. It could cause trouble.") : !this.initCustomTicker && this.destroyCustomTicker && console.warn("destroyCustomTicker callback is declared, but initCustomTicker is not. Please pay attention. It could cause trouble."), this.autoStart && this.start();
        });
    }
    destroy() {
        var t2;
        this.stop(), this._unbindEvents(), this.lenisInstance.destroy(), (t2 = this.coreInstance) == null || t2.destroy(), requestAnimationFrame(() => {
            var t3;
            (t3 = this.coreInstance) == null || t3.destroy();
        });
    }
    _bindEvents() {
        this._bindScrollToEvents(), this.autoResize && ("ResizeObserver" in window ? this.ROInstance = new a({ resizeElements: [document.body], resizeCallback: this._onResizeBind }) : window.addEventListener("resize", this._onResizeBind));
    }
    _unbindEvents() {
        this._unbindScrollToEvents(), this.autoResize && ("ResizeObserver" in window ? this.ROInstance && this.ROInstance.destroy() : window.removeEventListener("resize", this._onResizeBind));
    }
    _bindScrollToEvents(t2) {
        const s2 = t2 || this.lenisInstance.rootElement, e2 = s2 == null ? void 0 : s2.querySelectorAll("[data-scroll-to]");
        (e2 == null ? void 0 : e2.length) && e2.forEach((t3) => {
            t3.addEventListener("click", this._onScrollToBind, false);
        });
    }
    _unbindScrollToEvents(t2) {
        const s2 = t2 || this.lenisInstance.rootElement, e2 = s2 == null ? void 0 : s2.querySelectorAll("[data-scroll-to]");
        (e2 == null ? void 0 : e2.length) && e2.forEach((t3) => {
            t3.removeEventListener("click", this._onScrollToBind, false);
        });
    }
    _onResize() {
        requestAnimationFrame(() => {
            var t2;
            (t2 = this.coreInstance) == null || t2.onResize({ currentScroll: this.lenisInstance.scroll });
        });
    }
    _onRender() {
        var t2, s2;
        (t2 = this.lenisInstance) == null || t2.raf(Date.now()), (s2 = this.coreInstance) == null || s2.onRender({ currentScroll: this.lenisInstance.scroll, smooth: this.lenisInstance.isSmooth });
    }
    _onScrollTo(t2) {
        var s2;
        t2.preventDefault();
        const e2 = (s2 = t2.currentTarget) != null ? s2 : null;
        if (!e2)
            return;
        const i2 = e2.getAttribute("data-scroll-to-href") || e2.getAttribute("href"), r2 = e2.getAttribute("data-scroll-to-offset") || 0, l2 = e2.getAttribute("data-scroll-to-duration") || this.lenisOptions.duration || c.duration;
        i2 && this.scrollTo(i2, { offset: typeof r2 == "string" ? parseInt(r2) : r2, duration: typeof l2 == "string" ? parseInt(l2) : l2 });
    }
    start() {
        var t2;
        this.rafPlaying || ((t2 = this.lenisInstance) == null || t2.start(), this.rafPlaying = true, this.initCustomTicker ? this.initCustomTicker(this._onRenderBind) : this._raf());
    }
    stop() {
        var t2;
        this.rafPlaying && ((t2 = this.lenisInstance) == null || t2.stop(), this.rafPlaying = false, this.destroyCustomTicker ? this.destroyCustomTicker(this._onRenderBind) : this.rafInstance && cancelAnimationFrame(this.rafInstance));
    }
    removeScrollElements(t2) {
        var s2;
        t2 ? (this._unbindScrollToEvents(t2), (s2 = this.coreInstance) == null || s2.removeScrollElements(t2)) : console.error("Please provide a DOM Element as $oldContainer");
    }
    addScrollElements(t2) {
        var s2;
        t2 ? ((s2 = this.coreInstance) == null || s2.addScrollElements(t2), requestAnimationFrame(() => {
            this._bindScrollToEvents(t2);
        })) : console.error("Please provide a DOM Element as $newContainer");
    }
    resize() {
        this._onResizeBind();
    }
    scrollTo(t2, s2) {
        var e2;
        (e2 = this.lenisInstance) == null || e2.scrollTo(t2, { offset: s2 == null ? void 0 : s2.offset, lerp: s2 == null ? void 0 : s2.lerp, duration: s2 == null ? void 0 : s2.duration, immediate: s2 == null ? void 0 : s2.immediate, lock: s2 == null ? void 0 : s2.lock, force: s2 == null ? void 0 : s2.force, easing: s2 == null ? void 0 : s2.easing, onComplete: s2 == null ? void 0 : s2.onComplete });
    }
    _raf() {
        this._onRenderBind(), this.rafInstance = requestAnimationFrame(() => this._raf());
    }
}
export { h as default };