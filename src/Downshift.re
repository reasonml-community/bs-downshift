/* Common types */
type any;

/* Helpers */
let optionBoolToOptionJsBoolean = opt =>
  switch opt {
  | Some(true) => Some(Js.true_)
  | Some(false) => Some(Js.false_)
  | None => None
  };

external toAny : 'a => any = "%identity";

external toJsObj : any => Js.t({..}) = "%identity";

/* Types for Downshift API */
type item = any;

type otherStateToSet = Js.Dict.t(string);

type cb = unit => unit;

type itemToString = item => string;

type selectedItemChanged = (item, item) => bool;

type a11yStatusMessageOptions = {
  .
  "highlightedIndex": option(int),
  "highlightedValue": any,
  "inputValue": string,
  "isOpen": bool,
  "itemToString": itemToString,
  "previousResultCount": int,
  "resultCount": int,
  "selectedItem": item
};

type getA11yStatusMessage = a11yStatusMessageOptions => string;

type rootPropsOptions = {. "refKey": string};

type itemPropsOptions = {
  .
  "index": Js.Nullable.t(int),
  "item": any
};

module ControllerStateAndHelpers = {
  type t;
  /* Getters */
  [@bs.send] external getRootProps : (t, rootPropsOptions) => any = "";
  [@bs.send]
  external getButtonProps :
    (t, ~options: ReactDOMRe.reactDOMProps=?, unit) => any =
    "";
  [@bs.send]
  external getLabelProps :
    (t, ~options: ReactDOMRe.reactDOMProps=?, unit) => any =
    "";
  [@bs.send]
  external getInputProps :
    (t, ~options: ReactDOMRe.reactDOMProps=?, unit) => any =
    "";
  [@bs.send] external extGetItemProps : (t, itemPropsOptions) => any = "";
  [@bs.send]
  external itemPropsOptions : (t, ~options: itemPropsOptions) => any = "";
  /* Actions */
  [@bs.send] external openMenu : (t, ~cb: cb=?, unit) => unit = "";
  [@bs.send] external closeMenu : (t, ~cb: cb=?, unit) => unit = "";
  [@bs.send]
  external toggleMenu :
    (t, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) => unit =
    "";
  [@bs.send]
  external reset :
    (t, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) => unit =
    "";
  [@bs.send]
  external selectItem :
    (t, ~item: item, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) =>
    unit =
    "";
  [@bs.send]
  external selectItemAtIndex :
    (t, ~index: int, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) =>
    unit =
    "";
  [@bs.send]
  external selectHighlightedItem :
    (t, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) => unit =
    "";
  [@bs.send]
  external setHighlightedIndex :
    (t, ~index: int, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) =>
    unit =
    "";
  [@bs.send] external clearSelection : (t, ~cb: cb=?, unit) => unit = "";
  [@bs.send] external clearItems : (t, unit) => unit = "";
  [@bs.send] external itemToString : (t, item) => unit = "";
  /* State */
  [@bs.get] external highlightedIndex : t => Js.Nullable.t(int) = "";
  [@bs.get] external inputValue : t => Js.Nullable.t(string) = "";
  [@bs.get] external isOpen : t => bool = "";
  [@bs.get] external selectedItem : t => item = "";
  let getItemProps = (t, ~item: any, ~index=?, ()) : any => {
    let itemPropsOpt = {"item": item, "index": Js.Nullable.from_opt(index)};
    extGetItemProps(t, itemPropsOpt);
  };
};

type stateChangeOptions = {
  .
  "type": string,
  "highlightedIndex": int,
  "inputValue": string,
  "isOpen": bool,
  "selectedItem": item
};

type onChange = (any, ControllerStateAndHelpers.t) => unit;

type onSelect = (any, ControllerStateAndHelpers.t) => unit;

type onStateChange = (stateChangeOptions, ControllerStateAndHelpers.t) => unit;

type onInputValueChange = (string, ControllerStateAndHelpers.t) => unit;

type renderFunc = ControllerStateAndHelpers.t => ReasonReact.reactElement;

/* Expose the React component with the mapped props */
[@bs.module "downshift"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~defaultSelectedItem: option(any)=?,
      ~defaultHighlightedIndex: option(int)=?,
      ~defaultInputValue: option(string)=?,
      ~defaultIsOpen: option(bool)=?,
      ~itemToString: option(itemToString)=?,
      ~selectedItemChanged: option(selectedItemChanged)=?,
      ~getA11yStatusMessage: option(getA11yStatusMessage)=?,
      ~onChange: option(onChange)=?,
      ~onSelect: option(onSelect)=?,
      ~onStateChange: option(onStateChange)=?,
      ~onInputValueChange: option(onInputValueChange)=?,
      ~itemCount: option(int)=?,
      ~highlightedIndex: option(int)=?,
      ~inputValue: option(string)=?,
      ~isOpen: option(bool)=?,
      ~selectedItem: option(any)=?,
      ~render: renderFunc,
      ~id: option(string)=?,
      ~environment: option(Dom.window)=?,
      ~onOuterClick: option(unit => unit)=?,
      _children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "defaultSelectedItem": Js.Null_undefined.from_opt(defaultSelectedItem),
      "defaultHighlightedIndex":
        Js.Null_undefined.from_opt(defaultHighlightedIndex),
      "defaultInputValue": Js.Null_undefined.from_opt(defaultInputValue),
      "defaultIsOpen":
        Js.Null_undefined.from_opt(optionBoolToOptionJsBoolean(defaultIsOpen)),
      "itemToString": Js.Null_undefined.from_opt(itemToString),
      "selectedItemChanged": Js.Null_undefined.from_opt(selectedItemChanged),
      "getA11yStatusMessage": Js.Null_undefined.from_opt(getA11yStatusMessage),
      "onChange": Js.Null_undefined.from_opt(onChange),
      "onSelect": Js.Null_undefined.from_opt(onSelect),
      "onStateChange": Js.Null_undefined.from_opt(onStateChange),
      "onInputValueChange": Js.Null_undefined.from_opt(onInputValueChange),
      "itemCount": Js.Null_undefined.from_opt(itemCount),
      "highlightedIndex": Js.Null_undefined.from_opt(highlightedIndex),
      "inputValue": Js.Null_undefined.from_opt(inputValue),
      "isOpen": Js.Null_undefined.from_opt(optionBoolToOptionJsBoolean(isOpen)),
      "selectedItem": Js.Null_undefined.from_opt(selectedItem),
      "render": render,
      "id": Js.Null_undefined.from_opt(id),
      "environment": Js.Null_undefined.from_opt(environment),
      "onOuterClick": Js.Null_undefined.from_opt(onOuterClick)
    },
    [||]
  );
