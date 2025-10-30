# Libraries

| Name                     | Description |
|--------------------------|-------------|
| *libreservistencoin_cli*         | RPC client functionality used by *reservistencoin-cli* executable |
| *libreservistencoin_common*      | Home for common functionality shared by different executables and libraries. Similar to *libreservistencoin_util*, but higher-level (see [Dependencies](#dependencies)). |
| *libreservistencoin_consensus*   | Stable, backwards-compatible consensus functionality used by *libreservistencoin_node* and *libreservistencoin_wallet* and also exposed as a [shared library](../shared-libraries.md). |
| *libreservistencoinconsensus*    | Shared library build of static *libreservistencoin_consensus* library |
| *libreservistencoin_kernel*      | Consensus engine and support library used for validation by *libreservistencoin_node* and also exposed as a [shared library](../shared-libraries.md). |
| *libreservistencoinqt*           | GUI functionality used by *reservistencoin-qt* and *reservistencoin-gui* executables |
| *libreservistencoin_ipc*         | IPC functionality used by *reservistencoin-node*, *reservistencoin-wallet*, *reservistencoin-gui* executables to communicate when [`--enable-multiprocess`](multiprocess.md) is used. |
| *libreservistencoin_node*        | P2P and RPC server functionality used by *reservistencoind* and *reservistencoin-qt* executables. |
| *libreservistencoin_util*        | Home for common functionality shared by different executables and libraries. Similar to *libreservistencoin_common*, but lower-level (see [Dependencies](#dependencies)). |
| *libreservistencoin_wallet*      | Wallet functionality used by *reservistencoind* and *reservistencoin-wallet* executables. |
| *libreservistencoin_wallet_tool* | Lower-level wallet functionality used by *reservistencoin-wallet* executable. |
| *libreservistencoin_zmq*         | [ZeroMQ](../zmq.md) functionality used by *reservistencoind* and *reservistencoin-qt* executables. |

## Conventions

- Most libraries are internal libraries and have APIs which are completely unstable! There are few or no restrictions on backwards compatibility or rules about external dependencies. Exceptions are *libreservistencoin_consensus* and *libreservistencoin_kernel* which have external interfaces documented at [../shared-libraries.md](../shared-libraries.md).

- Generally each library should have a corresponding source directory and namespace. Source code organization is a work in progress, so it is true that some namespaces are applied inconsistently, and if you look at [`libreservistencoin_*_SOURCES`](../../src/Makefile.am) lists you can see that many libraries pull in files from outside their source directory. But when working with libraries, it is good to follow a consistent pattern like:

  - *libreservistencoin_node* code lives in `src/node/` in the `node::` namespace
  - *libreservistencoin_wallet* code lives in `src/wallet/` in the `wallet::` namespace
  - *libreservistencoin_ipc* code lives in `src/ipc/` in the `ipc::` namespace
  - *libreservistencoin_util* code lives in `src/util/` in the `util::` namespace
  - *libreservistencoin_consensus* code lives in `src/consensus/` in the `Consensus::` namespace

## Dependencies

- Libraries should minimize what other libraries they depend on, and only reference symbols following the arrows shown in the dependency graph below:

<table><tr><td>

```mermaid

%%{ init : { "flowchart" : { "curve" : "basis" }}}%%

graph TD;

reservistencoin-cli[reservistencoin-cli]-->libreservistencoin_cli;

reservistencoind[reservistencoind]-->libreservistencoin_node;
reservistencoind[reservistencoind]-->libreservistencoin_wallet;

reservistencoin-qt[reservistencoin-qt]-->libreservistencoin_node;
reservistencoin-qt[reservistencoin-qt]-->libreservistencoinqt;
reservistencoin-qt[reservistencoin-qt]-->libreservistencoin_wallet;

reservistencoin-wallet[reservistencoin-wallet]-->libreservistencoin_wallet;
reservistencoin-wallet[reservistencoin-wallet]-->libreservistencoin_wallet_tool;

libreservistencoin_cli-->libreservistencoin_util;
libreservistencoin_cli-->libreservistencoin_common;

libreservistencoin_common-->libreservistencoin_consensus;
libreservistencoin_common-->libreservistencoin_util;

libreservistencoin_kernel-->libreservistencoin_consensus;
libreservistencoin_kernel-->libreservistencoin_util;

libreservistencoin_node-->libreservistencoin_consensus;
libreservistencoin_node-->libreservistencoin_kernel;
libreservistencoin_node-->libreservistencoin_common;
libreservistencoin_node-->libreservistencoin_util;

libreservistencoinqt-->libreservistencoin_common;
libreservistencoinqt-->libreservistencoin_util;

libreservistencoin_wallet-->libreservistencoin_common;
libreservistencoin_wallet-->libreservistencoin_util;

libreservistencoin_wallet_tool-->libreservistencoin_wallet;
libreservistencoin_wallet_tool-->libreservistencoin_util;

classDef bold stroke-width:2px, font-weight:bold, font-size: smaller;
class reservistencoin-qt,reservistencoind,reservistencoin-cli,reservistencoin-wallet bold
```
</td></tr><tr><td>

**Dependency graph**. Arrows show linker symbol dependencies. *Consensus* lib depends on nothing. *Util* lib is depended on by everything. *Kernel* lib depends only on consensus and util.

</td></tr></table>

- The graph shows what _linker symbols_ (functions and variables) from each library other libraries can call and reference directly, but it is not a call graph. For example, there is no arrow connecting *libreservistencoin_wallet* and *libreservistencoin_node* libraries, because these libraries are intended to be modular and not depend on each other's internal implementation details. But wallet code is still able to call node code indirectly through the `interfaces::Chain` abstract class in [`interfaces/chain.h`](../../src/interfaces/chain.h) and node code calls wallet code through the `interfaces::ChainClient` and `interfaces::Chain::Notifications` abstract classes in the same file. In general, defining abstract classes in [`src/interfaces/`](../../src/interfaces/) can be a convenient way of avoiding unwanted direct dependencies or circular dependencies between libraries.

- *libreservistencoin_consensus* should be a standalone dependency that any library can depend on, and it should not depend on any other libraries itself.

- *libreservistencoin_util* should also be a standalone dependency that any library can depend on, and it should not depend on other internal libraries.

- *libreservistencoin_common* should serve a similar function as *libreservistencoin_util* and be a place for miscellaneous code used by various daemon, GUI, and CLI applications and libraries to live. It should not depend on anything other than *libreservistencoin_util* and *libreservistencoin_consensus*. The boundary between _util_ and _common_ is a little fuzzy but historically _util_ has been used for more generic, lower-level things like parsing hex, and _common_ has been used for reservistencoin-specific, higher-level things like parsing base58. The difference between util and common is mostly important because *libreservistencoin_kernel* is not supposed to depend on *libreservistencoin_common*, only *libreservistencoin_util*. In general, if it is ever unclear whether it is better to add code to *util* or *common*, it is probably better to add it to *common* unless it is very generically useful or useful particularly to include in the kernel.


- *libreservistencoin_kernel* should only depend on *libreservistencoin_util* and *libreservistencoin_consensus*.

- The only thing that should depend on *libreservistencoin_kernel* internally should be *libreservistencoin_node*. GUI and wallet libraries *libreservistencoinqt* and *libreservistencoin_wallet* in particular should not depend on *libreservistencoin_kernel* and the unneeded functionality it would pull in, like block validation. To the extent that GUI and wallet code need scripting and signing functionality, they should be get able it from *libreservistencoin_consensus*, *libreservistencoin_common*, and *libreservistencoin_util*, instead of *libreservistencoin_kernel*.

- GUI, node, and wallet code internal implementations should all be independent of each other, and the *libreservistencoinqt*, *libreservistencoin_node*, *libreservistencoin_wallet* libraries should never reference each other's symbols. They should only call each other through [`src/interfaces/`](`../../src/interfaces/`) abstract interfaces.

## Work in progress

- Validation code is moving from *libreservistencoin_node* to *libreservistencoin_kernel* as part of [The libreservistencoinkernel Project #24303](https://github.com/reservistencoin/reservistencoin/issues/24303)
- Source code organization is discussed in general in [Library source code organization #15732](https://github.com/reservistencoin/reservistencoin/issues/15732)
