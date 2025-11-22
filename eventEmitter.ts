type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void
}

class EventEmitter {

    private events : Map<string, Callback[]>;
    constructor(){
        this.events = new Map(); 
    }
    
    subscribe(eventName: string, callback: Callback): Subscription {

        if(!this.events.has(eventName)){
            this.events.set(eventName, []);
        }

    const listeners = this.events.get(eventName)!; 
            listeners.push(callback);
        

        return {
            unsubscribe: () => {
                const callBackToRemoveIndex = listeners.indexOf(callback);
                if(callBackToRemoveIndex !== -1){
                    listeners.splice(callBackToRemoveIndex, 1);
                }
            }
        };
    }
    
    emit(eventName: string, args: any[] = []): any[] {
        //Look up the listeners array for eventName.
        const listeners= this.events.get(eventName);
        if(!listeners){
            return [];
        }
        // 1. create a results array
        const results : any[] = [];
    for(let i =0; i < listeners.length; ++i){
        results.push(listeners[i](...args));
    }

    return results;

    }
}

/**
 * const emitter = new EventEmitter();
 *
 * Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */